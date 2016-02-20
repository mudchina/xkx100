//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "知府衙门");
	set ("long", @LONG
一座大厦，朱红的大门，门上钉着碗口大的铜钉，门外两盏大灯笼，
一盏写着“荆州府正堂”，另一盏写着“凌府”。门前两座石狮子。
LONG);
	set("exits", ([ 
		"east" : __DIR__"datang",
		"west" : __DIR__"xijie3",
	]));
	set("objects", ([
		__DIR__"obj/lion" : 2,
	]));

	set("coor/x", -1490);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
