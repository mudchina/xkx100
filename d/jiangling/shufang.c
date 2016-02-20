//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "书房");
	set ("long", @LONG
这是知府大人的书房。左面是一排书架，放着荆州府志，以及各种
各样的古书旧录。右面是一个古色古香的雕花木架，摆放了酒觞铜鼎，
金银玉器等各色古玩。正中一张大方桌，上面整齐地排列着文房四宝。
东边是一个走廊，南边是一个花圃，隐约可以闻到阵阵花的迷香。
LONG);
	set("exits", ([
		"east" : __DIR__"zoulang",
		"south" : __DIR__"huapu",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}