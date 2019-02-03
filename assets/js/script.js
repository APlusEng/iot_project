// Initialize Firebase
  var config = {
    apiKey: "AIzaSyDQEW0_j2wuZwcEMoxnrcB4nCX9Aalnnfw",
    authDomain: "dhniot.firebaseapp.com",
    databaseURL: "https://dhniot.firebaseio.com",
    projectId: "dhniot",
    storageBucket: "dhniot.appspot.com",
    messagingSenderId: "961728067508"
  };
  firebase.initializeApp(config);

	$(document).ready(function(){
		var database = firebase.database();
		var ledStatus;

		database.ref().on("value", function(snap)
		{
			ledStatus = snap.val().ledStatus;
			if(ledStatus == 1)
			{
				$(".lightStatus").text("The Light is on");
			}
			else
			{
				$(".lightStatus").text("The Light is Off");
			}
		});
		
		$(".buttonStatus").click(function(){
			var firebaseRef = firebase.database().ref().child("ledStatus");
			if(ledStatus == 1)
			{
				firebaseRef.set(0);
				ledStatus = 0;
			}
			else
			{
				firebaseRef.set(1);
				ledStatus = 1;
			}
		});

	});

