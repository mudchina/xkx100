// /kaifeng/shanlu2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create ()
{
	set ("short", "山路");
	set ("long", @LONG
这是一条黄土飞扬的山路，因为离嵩山等几处山脉还比较远，所以
它很是宽阔，路上来往的行人很多，路边相隔不远就有个小亭子供行人
歇脚，北边不远便是嵩山。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"north"  : "/d/songshan/taishique",
		"eastup" : __DIR__"shanlu1",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
