/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 University of Washington
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Leonard Tracy <lentracy@gmail.com>
 */


/**
 * \file uan-cw-example.cc
 * \ingroup uan
 *
 * This example showcases the "CW-MAC" described in System Design Considerations
 * for Undersea Networks article in the IEEE Journal on Selected Areas of
 * Communications 2008 by Nathan Parrish, Leonard Tracy and Sumit Roy.
 * The MAC protocol is implemented in the class UanMacCw.  CW-MAC is similar
 * in nature to the IEEE 802.11 DCF with a constant backoff window.
 * It requires two parameters to be set, the slot time and
 * the contention window size.  The contention window size is
 * the backoff window size in slots, and the slot time is
 * the duration of each slot.  These parameters should be set
 * according to the overall network size, internode spacing and
 * the number of nodes in the network.
 *
 * This example deploys nodes randomly (according to RNG seed of course)
 * in a finite square region with the X and Y coordinates of the nodes
 * distributed uniformly.  The CW parameter is varied throughout
 * the simulation in order to show the variation in throughput
 * with respect to changes in CW.
 */

#include "uan-cw-example.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/stats-module.h"
#include "ns3/applications-module.h"

#include "ns3/netanim-module.h"
#include <fstream>

#include<bits/stdc++.h>
uint32_t T=0;
double t=0;
uint64_t K=0;
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("UanCwRutExample");

Experiment::Experiment ()
  : m_numNodes (10),
    m_dataRate (80),
    m_depth (70),
    m_boundary (1500),
    m_packetSize (32),
    m_bytesTotal (0),
    m_cwMin (10),
    m_cwMax (30),
    m_cwStep (10),
    m_avgs (3),
    m_slotTime (Seconds (2.2)),
    m_simTime (Seconds (1000)),
    m_gnudatfile ("uan-cw-myexample.gpl"),
    m_asciitracefile ("uan-cw-myexample.asc"),
    m_bhCfgFile ("uan-apps/dat/default.cfg")
{
/////std::cout<<"Initialize"<<std::endl;
}

void Experiment::ResetData (){

    NS_LOG_DEBUG (Simulator::Now ().GetSeconds () << "  Resetting data : ");
    m_throughputs.push_back (m_bytesTotal * 8.0 / m_simTime.GetSeconds ());
    m_bytesTotal = 0;
}

void Experiment::IncrementCw (uint32_t cw){

    NS_ASSERT (m_throughputs.size () == m_avgs);

    double avgThroughput = 0.0;
    for (uint32_t i=0; i<m_avgs; i++){

        avgThroughput += m_throughputs[i];
    }
    avgThroughput /= m_avgs;

    m_data.Add (cw, avgThroughput);
    m_throughputs.clear ();

    Config::Set ("/NodeList/*/DeviceList/*/Mac/CW", UintegerValue (cw + m_cwStep));

    SeedManager::SetRun (SeedManager::GetRun () + 1);

    NS_LOG_DEBUG ("Average for cw=" << cw << " over " << m_avgs << " runs: " << avgThroughput);
}

void Experiment::UpdatePositions (NodeContainer &nodes){

  NS_LOG_DEBUG (Simulator::Now ().GetSeconds () << " Updating positions");
  NodeContainer::Iterator it = nodes.Begin ();
  Ptr<UniformRandomVariable> uv = CreateObject<UniformRandomVariable> ();

  for (uint32_t i=0,x,y; it != nodes.End () && i<m_numNodes/2; i++,it++)
    {
      Ptr<MobilityModel> mp = (*it)->GetObject<MobilityModel> ();
      mp->SetPosition (Vector ( (x=uv->GetValue (500,1000) ), (y=uv->GetValue (0, m_boundary) ), 70.0));
      ///std::cout<<i<<"). "<<x<<" "<<y<<std::endl;
      //anim.SetConstantPosition(it->Get(),x,y);
    }
     for (uint32_t x,y,i=m_numNodes/2; it != nodes.End (); i++,it++)
    {
      Ptr<MobilityModel> mp = (*it)->GetObject<MobilityModel> ();
      mp->SetPosition (Vector ( (x=uv->GetValue (00,500) ), (y=uv->GetValue (0, m_boundary) ), 70.0));
      ///std::cout<<i<<"). "<<x<<" "<<y<<std::endl;
      //anim.SetConstantPosition(it->Get(),x,y);
    }
}

void Experiment::ReceivePacket (Ptr<Socket> socket){

    Ptr<Packet> packet;

    while ((packet = socket->Recv ())){

        m_bytesTotal += packet->GetSize ();
    }
    if(K>=1201)exit(0);
    K++;
   ///std::cout<<K<<std::endl;

    packet = 0;
}

Gnuplot2dDataset Experiment::Run (UanHelper &uan){


    uan.SetMac ("ns3::UanMacCw", "CW", UintegerValue (m_cwMin), "SlotTime", TimeValue (m_slotTime));
    NodeContainer nc = NodeContainer ();
    NodeContainer sink = NodeContainer ();
    nc.Create (m_numNodes/2);
    sink.Create (1);

    NodeContainer nc2=NodeContainer();
    NodeContainer sink2 = NodeContainer ();
    nc2.Create(m_numNodes/2);
    sink2.Create(1);

    PacketSocketHelper socketHelper;
    socketHelper.Install (nc);
    socketHelper.Install (sink);

    PacketSocketHelper socketHelper2;
    socketHelper2.Install (nc2);
    socketHelper2.Install (sink2);

/*
#ifdef UAN_PROP_BH_INSTALLED
  Ptr<UanPropModelBh> prop = CreateObjectWithAttributes<UanPropModelBh> ("ConfigFile", StringValue ("exbhconfig.cfg"));
#else
*/
    Ptr<UanPropModelIdeal> prop = CreateObjectWithAttributes<UanPropModelIdeal> ();
    Ptr<UanPropModelIdeal> prop2 = CreateObjectWithAttributes<UanPropModelIdeal> ();
//#endif //UAN_PROP_BH_INSTALLED

    Ptr<UanChannel> channel = CreateObjectWithAttributes<UanChannel> ("PropagationModel", PointerValue (prop));

    Ptr<UanChannel> channel2 = CreateObjectWithAttributes<UanChannel> ("PropagationModel", PointerValue (prop2));

    //Create net device and nodes with UanHelper
    NetDeviceContainer devices = uan.Install (nc, channel);
    NetDeviceContainer sinkdev = uan.Install (sink, channel);

    NetDeviceContainer devices2=uan.Install (nc2, channel2);
    NetDeviceContainer sinkdev2 = uan.Install (sink2, channel2);

    MobilityHelper mobility;
    Ptr<ListPositionAllocator> pos = CreateObject<ListPositionAllocator> ();


    Ptr<UniformRandomVariable> urv = CreateObject<UniformRandomVariable> ();
    pos->Add (Vector (250, m_boundary / 2.0, m_depth));
    pos->Add (Vector (1250, m_boundary / 2.0, m_depth));

    for (uint32_t i = 0; i < m_numNodes/2; i++)
      {
        double x = urv->GetValue (0, 500);
        double y = urv->GetValue (0, 1500);
        pos->Add (Vector (x, y, m_depth));

      }
      for (uint32_t i = m_numNodes/2; i < m_numNodes; i++)
      {
        double x = urv->GetValue (1000, 1500);
        double y = urv->GetValue (0, 1500);
        pos->Add (Vector (x, y, m_depth));

      }

    mobility.SetPositionAllocator (pos);
    mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
    mobility.Install (sink);
    mobility.Install (sink2);
    mobility.Install (nc);
    mobility.Install (nc2);

    NS_LOG_DEBUG ("Position of sink: "
                  << sink.Get (0)->GetObject<MobilityModel> ()->GetPosition ());

    NS_LOG_DEBUG ("Position of sink2: "
                  << sink2.Get (0)->GetObject<MobilityModel> ()->GetPosition ());



    PacketSocketAddress socket;
    socket.SetSingleDevice (sinkdev.Get (0)->GetIfIndex ());
    socket.SetPhysicalAddress (sinkdev.Get (0)->GetAddress ());
    socket.SetProtocol (0);

    PacketSocketAddress socket2;
    socket2.SetSingleDevice (sinkdev2.Get (0)->GetIfIndex ());
    socket2.SetPhysicalAddress (sinkdev2.Get (0)->GetAddress ());
    socket2.SetProtocol (0);


    OnOffHelper app ("ns3::PacketSocketFactory", Address (socket));
    app.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1]"));
    app.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0]"));
    app.SetAttribute ("DataRate", DataRateValue (m_dataRate));
    app.SetAttribute ("PacketSize", UintegerValue (m_packetSize));

    OnOffHelper app2 ("ns3::PacketSocketFactory", Address (socket2));
    app2.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1]"));
    app2.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0]"));
    app2.SetAttribute ("DataRate", DataRateValue (m_dataRate));
    app2.SetAttribute ("PacketSize", UintegerValue (m_packetSize));

    ApplicationContainer apps ;
        apps= app.Install (nc);
        apps= app.Install (nc2);

    apps.Start (Seconds (0.5));
    Time nextEvent = Seconds (0.5);


    for (uint32_t cw = m_cwMin; cw <= m_cwMax; cw += m_cwStep)
      {

        ///std::cout<<cw<<std::endl;
        for (uint32_t an = 0; an < m_avgs; an++)
          {
                nextEvent += m_simTime;
                Simulator::Schedule (nextEvent, &Experiment::ResetData, this);
                ///std::cout<<"UPDATE POSITION [0....4]"<<std::endl;
                Simulator::Schedule (nextEvent, &Experiment::UpdatePositions, this, nc);
                ///std::cout<<"UPDATE POSITION [6....10]"<<std::endl;
                Simulator::Schedule (nextEvent, &Experiment::UpdatePositions, this, nc2);
          }
            Simulator::Schedule (nextEvent, &Experiment::IncrementCw, this, cw);
      }

    apps.Stop (nextEvent + m_simTime);

    Ptr<Node> sinkNode = sink.Get (0);
       Ptr<Node> sinkNode2 = sink2.Get (0);

    TypeId psfid = TypeId::LookupByName ("ns3::PacketSocketFactory");
        TypeId psfid2 = TypeId::LookupByName ("ns3::PacketSocketFactory");

    if (sinkNode->GetObject<SocketFactory> (psfid) == 0)
      {
        Ptr<PacketSocketFactory> psf = CreateObject<PacketSocketFactory> ();
        sinkNode->AggregateObject (psf);
      }

    if (sinkNode2->GetObject<SocketFactory> (psfid2) == 0)
      {
        Ptr<PacketSocketFactory> psf2 = CreateObject<PacketSocketFactory> ();
        sinkNode2->AggregateObject (psf2);
      }

    Ptr<Socket> sinkSocket = Socket::CreateSocket (sinkNode, psfid);
    Ptr<Socket> sinkSocket2 = Socket::CreateSocket (sinkNode2, psfid2);


    sinkSocket->Bind (socket);
    sinkSocket2->Bind (socket2);

    sinkSocket->SetRecvCallback (MakeCallback (&Experiment::ReceivePacket, this));
    sinkSocket2->SetRecvCallback (MakeCallback (&Experiment::ReceivePacket, this));


    m_bytesTotal = 0;

    std::ofstream ascii (m_asciitracefile.c_str ());
    if (!ascii.is_open ())
      {
        NS_FATAL_ERROR ("Could not open ascii trace file: "
                        << m_asciitracefile);
      }
    uan.EnableAsciiAll (ascii);


    /*anim.SetConstantPosition(sink.Get(0),)*/
  AnimationInterface anim("uan-cw-rutexample.xml");


    //Simulator :: Stop(Seconds (40));
    T=(clock()-t)/CLOCKS_PER_SEC;
    ///std::cout<<"T : "<<T<<std::endl;
    Simulator::Run ();



    sinkNode = 0;
   sinkSocket= 0;
    pos = 0;
    channel = 0;
    prop = 0;
    sinkNode2 = 0;
    sinkSocket2 = 0;
   //pos2 = 0;
    channel2 = 0;
    prop2 = 0;

    for (uint32_t i=0; i < nc.GetN (); i++)
      {
        nc.Get (i) = 0;
      }
    for (uint32_t i=0; i < sink.GetN (); i++)
      {
        sink.Get (i) = 0;
      }

    for (uint32_t i=0; i < devices.GetN (); i++)
      {
        devices.Get (i) = 0;
      }
    for (uint32_t i=0; i < sinkdev.GetN (); i++)
      {
        sinkdev.Get (i) = 0;
      }



    for (uint32_t i=0; i < nc2.GetN (); i++)
      {
        nc2.Get (i) = 0;
      }
    for (uint32_t i=0; i < sink2.GetN (); i++)
      {
        sink2.Get (i) = 0;
      }

    for (uint32_t i=0; i < devices2.GetN (); i++)
      {
        devices2.Get (i) = 0;
      }
    for (uint32_t i=0; i < sinkdev2.GetN (); i++)
      {
        sinkdev2.Get (i) = 0;
      }
        //Simulator :: Stop(Seconds (40));
    T=(clock()-t)/CLOCKS_PER_SEC;
    ///std::cout<<"T : "<<T<<std::endl;

    Simulator::Destroy ();
    return m_data;
}

int
main (int argc, char **argv)
{
    t=clock();
    T=(clock()-t)/CLOCKS_PER_SEC;
    ///std::cout<<"T : "<<T<<std::endl;

  LogComponentEnable ("UanCwRutExample", LOG_LEVEL_INFO);

  Experiment exp;

  std::string gnudatfile ("cwmyexpgnuout.dat");
  std::string perModel = "ns3::UanPhyPerGenDefault";
  std::string sinrModel = "ns3::UanPhyCalcSinrDefault";

  CommandLine cmd;
  cmd.AddValue ("NumNodes", "Number of transmitting nodes", exp.m_numNodes);
  cmd.AddValue ("Depth", "Depth of transmitting and sink nodes", exp.m_depth);
  cmd.AddValue ("RegionSize", "Size of boundary in meters", exp.m_boundary);
  cmd.AddValue ("PacketSize", "Generated packet size in bytes", exp.m_packetSize);
  cmd.AddValue ("DataRate", "DataRate in bps", exp.m_dataRate);
  cmd.AddValue ("CwMin", "Min CW to simulate", exp.m_cwMin);
  cmd.AddValue ("CwMax", "Max CW to simulate", exp.m_cwMax);
  cmd.AddValue ("SlotTime", "Slot time duration", exp.m_slotTime);
  cmd.AddValue ("Averages", "Number of topologies to test for each cw point", exp.m_avgs);
  cmd.AddValue ("GnuFile", "Name for GNU Plot output", exp.m_gnudatfile);
  cmd.AddValue ("PerModel", "PER model name", perModel);
  cmd.AddValue ("SinrModel", "SINR model name", sinrModel);
  cmd.Parse (argc, argv);

  ObjectFactory obf;
  obf.SetTypeId (perModel);
  Ptr<UanPhyPer> per = obf.Create<UanPhyPer> ();
  obf.SetTypeId (sinrModel);
  Ptr<UanPhyCalcSinr> sinr = obf.Create<UanPhyCalcSinr> ();

  UanHelper uan;
  UanTxMode mode;
  mode = UanTxModeFactory::CreateMode (UanTxMode::FSK, exp.m_dataRate,
                                       exp.m_dataRate, 12000,
                                       exp.m_dataRate, 2,
                                       "Default mode");
  UanModesList myModes;
  myModes.AppendMode (mode);

  uan.SetPhy ("ns3::UanPhyGen",
              "PerModel", PointerValue (per),
              "SinrModel", PointerValue (sinr),
              "SupportedModes", UanModesListValue (myModes));

  Gnuplot gp;
  Gnuplot2dDataset ds;
  ds = exp.Run (uan);

  gp.AddDataset (ds);

  std::ofstream of (exp.m_gnudatfile.c_str ());
  if (!of.is_open ())
    {
      NS_FATAL_ERROR ("Can not open GNU Plot outfile: " << exp.m_gnudatfile);
    }
  gp.GenerateOutput (of);

  per = 0;
  sinr = 0;

}

