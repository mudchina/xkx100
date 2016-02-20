// Room: /d/yueyang/loumen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岳阳楼门");
	set("long", @LONG
这里是岳阳楼的大门，门上是一幅黑底蓝字对联“洞庭天下水，岳
阳天下楼”。岳阳楼建在岳阳城楼上，建筑精巧雄伟，与洪都滕王阁、
武昌黄鹤楼并称江南三大名楼，
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"huaiputing",
		"southdown" : __DIR__"ximen",
	]));
	set("coor/x", -1430);
	set("coor/y", -2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
