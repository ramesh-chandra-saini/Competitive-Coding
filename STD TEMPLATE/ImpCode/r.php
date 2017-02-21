<?php include('connection.php'); ?>
<?php 
  $sql="SELECT 
        DoctorBasicInfo.DoctorId AS DoctorId, 
        DoctorBasicInfo.DeptId AS DeptId, 
        DoctorBasicInfo.PhoneNumber AS PhoneNumber, 
        DoctorBasicInfo.Name AS Name, 
        DoctorBasicInfo.Age AS Age, 
        DoctorBasicInfo.Fee AS Fee, 
        DoctorBasicInfo.Photo AS Photo, 
        DoctorBasicInfo.EmailId AS EmailId, 
        DoctorBasicInfo.Address AS Address,

        DoctorAdvInfo.Exp AS Exp, 
        DoctorAdvInfo.Photo AS PrimaryLanguage, 
        DoctorAdvInfo.EmailId AS SecondaryLanguage, 
        DoctorAdvInfo.Address AS OtherLanguage

        FROM DoctorBasicInfo JOIN DepartmentInfo 
        ON DoctorBasicInfo.DoctorId = DoctorAdvInfo.DoctorId
        WHERE 1";

    $res=mysqli_query($conn,$sql);
    $response = array();
    $response["success"]= "true";
    $data = array();
    if (!$res) 
        $data = null;
    else
        while($row=mysqli_fetch_array($res))
            $data[]=array( 
                           'doctorId' => $row['DoctorId'],
                           'deptId' => $row['DeptId'],
                           'phoneNumber' => $row['PhoneNumber'],
                           'name' => $row['Name'],
                           'age' => $row['Age'],
                           'fee' => $row['Fee'],
                           'photo' => $row['Photo'],
                           'emailId' => $row['EmailId'],
                           'address' => $row['Address'],
                           'exp' => $row['Exp'],
                           'primaryLanguage' => $row['PrimaryLanguage'],
                           'secondaryLanguage' => $row['SecondaryLanguage'],
                           'otherLanguage' => $row['OtherLanguage']
                         );
    $response["data"] = $data;   
    $response = json_encode($response);
    echo $response;
   $conn->close();
?>	
