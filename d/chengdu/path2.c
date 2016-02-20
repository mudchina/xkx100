// Room: path2.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "溪岸小路");
	set("long", @LONG
溪源转北，阵阵水响带着你来到草堂前。站在草堂照壁前，回首
浣花溪，想象万红漂坠，少女清歌浣花时节，别是一般滋味。西北边
就是“万里桥西宅，百花潭北庄”的杜甫草堂了。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"northwest"  : __DIR__"path3",
		"northeast"  : __DIR__"huanhuaxi1",
		"southwest"  : __DIR__"path1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
