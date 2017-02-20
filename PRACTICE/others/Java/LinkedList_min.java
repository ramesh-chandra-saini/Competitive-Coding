import java.io.*;
import java.util.*;

class Node{

	private int data;
	private Node Link;
	Node(){
		this.data=0;
		this.Link=null;
	}
	Node(int data){
		this.data=data;
		this.Link=null;
	}
	public void insert(int data,Node root ){
		
		if(root.Link==null)
			root=new Node(data);
		else{
				Node newNode=new Node(data);
				newNode.data=data;
				newNode.Link=null;
				Node iterator=root;
				while(iterator.Link!=null)
					iterator=iterator.Link;
				iterator.Link=newNode;
		}
		printList(root);
	}
	public void printList(Node root){
		Node iterator=root;
		while(iterator.Link!=null){
			System.out.printf("%d --> ",iterator.data);
			iterator=iterator.Link;
		}
		System.out.println();
		return ;
	}
}

public class LinkedList{
	public static void main(String [] args){
		Node root=new Node();
		insert(1,root);
		insert(2,root);
	}
}