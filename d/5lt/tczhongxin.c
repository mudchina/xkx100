// Room: /d/5lt/tczhongxin.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "体彩中心");
	set  ("long",  @LONG
没错，这里就是村里的体彩中心。每逢周末，兑奖大厅里都要人满
为患。遍地的烟头、狂热的彩民，刚到这儿的人可能很不习惯，然而这
里是出产百万富翁的地方，越来越多的人加入了彩民们的队伍。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"sroad3",
	]));

	set("coor/x", -140);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
