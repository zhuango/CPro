<?php
$file = 'php.file';
$num = 0;

if(!$fso=fopen($file,'w')){
	$this->warns('can\'t open this file');//trigger_error
	return false;
}

if (is_writable($file) == false) {
	die("Oh, Bad!");
}

$data ="ddddddddsd\n";
while($num != 1000000){
     if(!fwrite($fso,$data)){
		$this->warns('can\' not write in');//trigger_error
		return false;
	 }
	$num += 1;
}
