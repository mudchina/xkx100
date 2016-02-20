// Room: /d/yanziwu/juanxin.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "倦心亭");
	set("long", @LONG
倦心亭正在蔓陀山峰崖下。崖上飞瀑直指莲韵塘底，风声雨气，让
人浑然忘却人世间的烦恼。这里常有伤心人流连抒怀。亭中石桌上刻着
“曾经沧海难为水  除却巫山不是云  取次花丛懒回顾  半缘修道半缘
君。”笔致甚为都雅。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"bridge3",
	]));
	set("coor/x", 1220);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}