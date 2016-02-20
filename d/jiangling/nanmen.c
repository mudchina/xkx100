//Edited by fandog, 02/18/2000
inherit ROOM;
void create()
{
	set("short", "南门");
	set("long", @LONG
这是荆州南城门。城墙上，赫然可见三行用石灰泥书写的数目字。
每个字都是尺许见方，远远便能望见，“四、五十一、三十三、二十八
……”奇怪的是，这几行字离地二丈有余。北边就是荆州城了，南边是
一条山道，蜿蜒伸展通向城南一片乱石冈。
LONG );
	set("outdoors", "jiangling");
	set("exits", ([
		"south" : __DIR__"shandao1",
		"north" : __DIR__"xijie4",
	]));
	set("objects", ([
		__DIR__"npc/jiaoshu"   : 1,
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 2,
	]));
	set("coor/x", -1500);
	set("coor/y", -2050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}