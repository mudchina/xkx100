inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
这是一条小径，弯弯曲曲向远方延伸。小径两边种植了一些桃花树。
你只一瞥就发现：这些桃花全是白色的。
LONG );
	set("exits", ([
		"east" : __DIR__"road2",
		"west" : __DIR__"taohua1",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"taohua1",
	]));
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
       	replace_program(ROOM);
}