<?php

// $data =$_POST('data');
// $jsonString = $data

$name = $_POST('nama');

$jsonString =  '[{ "nama" : , "umur" : 99 },{ "nama" : "Yody", "umur" : 20 }]';

// $jsonString = '[{ "nama" : "admin", "umur" : 99 },{ "nama" : "Yody", "umur" : 20 }]';

// $arr = json_decode($jsonString,true);

// var_dump($arr);

// $file = fopen("tes.txt","w");

// for ($i=0; $i <count($arr) ; $i++) { 
// 	fwrite($file,$arr[$i]['nama']);
// 	echo $arr[$i]['nama']."<br/>";
// }

// fclose($file);
echo $json;

	
?>