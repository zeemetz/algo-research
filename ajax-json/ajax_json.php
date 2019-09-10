<html>
<head>
	<title>ajax_json_tes</title>
	<script type="text/javascript" src='jquery.js'></script>
	<script type="text/javascript">
	// var xhr = new XMLHttpRequest();

	
	// xhr.open('get', 'data.php');
	// xhr.send(null);

	// xhr.onreadystatechange = function(){
	//     if(xhr.readyState === 4){
	//         if(xhr.status === 200){
	// 			alert(xhr.responseText); 
	// 			var member = [
	// 				{ "nama" :  xhr.responseText, "angkatan" : "13-0", "umur" : 20}
	// 			];
	// 			alert(member[0].nama);
	//         }else{
	//             alert('Error: '+xhr.status); 
	//         }
	//     }
	// }

	// var member = [
	// 	{"nama":"yody","umur":20}
	// ];

	// $.ajax({
	// 	type:"GET",
	// 	url:"data.php",
	// 	data:member
	// }).done(function(data){alert(data.nama)});

	// var a = $.ajax({
	// 	type:"GET",
	// 	url:"data.php"
	// });	

	var json = [{ "nama" : "admin", "umur" : 99 },{ "nama" : "Yody", "umur" : 20 }];

	$.post("data.php",json).done(alert("clean"));

	$.get("data.php", function(data){

		var obj = JSON.parse(data);
		//alert(obj[0].nama);
		$.each(obj, function(item,i){
			alert(i.nama);
		});

	}).fail(function(){alert("failed")});
		

	</script>
</head>
<body>

</body>
</html>