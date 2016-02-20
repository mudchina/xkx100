// wdroad9.c 黄土路
// Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖
北境界，据说经常有土匪出没，不可久留。向东南去可至江陵。
LONG );
	set("outdoors", "sanbuguan");
	set("exits", ([
		"northwest" : __DIR__"sanbuguan",
		"south"     : __DIR__"wdroad10",
		"southeast" : "/d/jiangling/tulu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
