//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "黄鹤楼");
	set ("long", @LONG
黄鹤楼与湖南的岳阳楼、江西的滕王阁并称江南三大名楼。关于此
楼的来历有许多传说：有说古时仙人乘鹤路经此地；有说吕洞宾曾在此
羽化飞仙。但流传最广的，是说古时有位道士，一天在左近一家酒肆中
用桔皮画了只鹤，并告知酒肆主人，如有客人来此饮酒，只要一拍手，
鹤即翩然起舞，以助酒兴。此后，来此饮酒的客人越来越多，酒肆生意
格外兴隆。十年后，道士复至，拈奏铁笛，但见白云飞来，鹤亦飞舞，
道人遂驾鹤而去。酒肆主人为了纪念这位道士，就在这里建了一座“黄
鹤楼”。这里向来是文人荟萃，宴客送友的胜地。东边是一面湖水，北
面是大江，江中但见一柱石壁擎天。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"north" : __DIR__"chibi",
		"east"  : __DIR__"donghu",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
