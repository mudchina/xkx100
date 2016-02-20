// Room: /d/luoyang/road10.c
// Last modified by winder 2002.11.11

inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。道路两边，是一
排排高树。树林之外，便是一片片的农田了。田地里传来农人的呼号，
几头黄牛悠闲的趴卧着。
LONG);
	set("exits", ([  /*  sizeof()  ==  2  */
		"east" : __DIR__"road9",
		"west" : __DIR__"road11",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -150);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
