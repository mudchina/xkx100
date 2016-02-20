// Room: /d/5lt/dating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是无厘头电视台的大厅。大厅面积很大，足有三个篮球场那么
大，地板是光滑的大理石，可以玩单排。门口坐着一个保安阿达，他负
责保护电视台的安全以及一些基本的迎宾工作。大厅上方有个金匾，上
面写着 5LTTV几个大字，显得格外的醒目。东边有一个小门，通向电视
台的新闻发布中心。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"up"     : __DIR__"mishuchu",
		"out"    : __DIR__"mubanlu",
		"east"   : __DIR__"fbzhongxin",
	]));
        set("objects", ([
		__DIR__"npc/ahda": 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
