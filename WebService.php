<?php

	/* soak in the passed variable or set our own */

	$number = isset($_GET['num']) ? intval($_GET['num']) : 1; //10 is the default
	$table = isset($_GET['tabla']) ? strval($_GET['tabla']) : temperatura;
	$format = strtolower($_GET['format']) == 'json' ? 'json' : 'json'; //xml is the default

	/* connect to the db */
	$link = mysqli_connect("localhost","pti20","pti20pti20","meteo") or die('Cannot connect to the DB');
//	mysqli_select_db("meteo",$link) or die('Cannot select the DB');
  session_start();

	/* grab the posts from the db */
//	$query = mysqli_query($link,"SELECT ALL FROM temperatura");
	//$result = mysqli_query($query,$link) or die('Errant query:  '.$query);

	$query = mysqli_query($link,"SELECT * FROM $table LIMIT $number");

	echo json_encode($query);

	/* create one master array of the records */
	$posts = array();
	if(mysqli_num_rows($query)) {
		while($post = mysqli_fetch_assoc($query)) {
			$posts[] = array('post'=>$post);
		}
	}
  echo $posts[1];
	/* output in necessary format */
	if($format == 'json') {
//		header('Content-type: application/json');
		echo json_encode($posts);
	}
	else {
		header('Content-type: text/xml');
		echo '<posts>';
		foreach($posts as $index => $post) {
			if(is_array($post)) {
				foreach($post as $key => $value) {
					echo '<',$key,'>';
					if(is_array($value)) {
						foreach($value as $tag => $val) {
							echo '<',$tag,'>',htmlentities($val),'</',$tag,'>';
						}
					}
					echo '</',$key,'>';
				}
			}
		}
		echo '</posts>';
	}

	/* disconnect from the db */
	@mysqli_close($link);

?>
