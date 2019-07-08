<!DOCTYPE html>
<html>
<head>
	<title> Smart Dhangadhi </title>
	<link rel="stylesheet" type="text/css" href="assets/css/bootstrap.css">
	<link rel="stylesheet" href="assets/css/font-awesome-4.7.0/css/font-awesome.min.css">
	<!-- <link href="https://gitcdn.github.io/bootstrap-toggle/2.2.2/css/bootstrap-toggle.min.css" rel="stylesheet"> -->

	<link rel="stylesheet" type="text/css" href="assets/css/style.css">

	<script type="text/javascript" src="assets/js/jquery-3.3.1.js"></script>
<!-- <script src="https://gitcdn.github.io/bootstrap-toggle/2.2.2/js/bootstrap-toggle.min.js"></script> -->

	<script src="https://www.gstatic.com/firebasejs/5.8.2/firebase.js"></script>
	<script type="text/javascript" src="assets/js/script.js"></script>
	<!-- Image and text -->
<nav class="navbar navbar-light bg-primary">
  
    <h5 class="brand">SmartGhar</h5>
  

</nav>
</head>
<body >

	<!-- <div class="container" >
		<div class="row">
			<div class="col-md-1.5">
				<?php  include("pages/sidebar.php");?>
				
			</div>
			<div class="col-md-4 room1">
				<label class="btn btn-primary">Room No. 1 Control Panel</label>
				
				<div>
					<h6>Light is on</h6>
					<button class="btn btn-primary">Light 1</button>

				</div>

			</div>


			<!-- for room2 --><!-- 
			<div class="col-md-6 room1">
				<label class="btn btn-primary">Room No. 2 Control Panel</label>
				
				<div>
					<h6>Light is on</h6>
					<button class="btn btn-primary">Light 1</button>

				</div>
				<div style="padding-top: 20px;">
					<h6>Light is on</h6>
					<button class="btn btn-primary">Light 2</button>

				</div>
			</div> -->
			<!-- for kitchen -->
			<!-- 
		</div>

	</div> -->
	











	<div class="container">
		<div class="row">
			<div class="col-md-12" style="margin-top: 50px">
				<h3 class="lightStatus"></h3>
				<button class="btn btn-danger buttonStatus">Click</button>
			</div>
		</div>
		<div class="row">
			<div class="col-md-12" style="margin-top: 50px">
				<h3 class="fanStatus"></h3>
				<button class="btn btn-danger fanButton">Click</button>
			</div>
		</div>
		<div class="row">
			<div class="col-md-12" style="margin-top: 50px">
				<h3 class="tvStatus"></h3>
				<button class="btn btn-danger tvButton">Click</button>
			</div>
		</div>
		<div class="row">
			<div class="col-md-12" style="margin-top: 50px">
				<h3 class="acStatus"></h3>
				<button class="btn btn-danger acButton">Click</button>
			</div>
		</div>
	</div>
</body>
</html>