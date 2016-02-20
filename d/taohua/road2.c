inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
这是一条小径，弯弯曲曲向远方延伸。小径两边种植了一些桃花树。
你只一瞥就发现：这些桃花全是白色的。
LONG);
	set("exits", ([
		"west" : __DIR__"road1",
		"east" : __DIR__"road3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taohua");
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}