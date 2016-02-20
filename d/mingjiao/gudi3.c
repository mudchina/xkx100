// Room: /d/mingjiao/gudi3.c

inherit ROOM;

void create()
{
	set("short", "昆仑仙境");
	set("long", @LONG
出得洞来，面前竟是个花团锦簇的翠谷，红花绿树，交相掩映。脚
下踏著的是柔软细草，鼻中闻到的是清幽花香，鸣禽间关，鲜果悬枝，
哪想得到在这黑黝黝的洞穴之后，竟会有这样一个洞天福地？离地丈许
高处有一山洞(dong)。
LONG );
	set("outdoors", "mingjiao");
	set("exits", ([
		"west"  : __DIR__"gudi5",
		"south" : __DIR__"gudi4",
	]));
	set("item_desc", ([
		"dong": "一个不知深浅的山洞。\n",
	]));
	set("objects", ([
		__DIR__"npc/sheep" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 800);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me = this_player();
	int n = me->query("str");
	if( !arg || arg != "dong")
	{
		write("你想干什么呀?\n");
		return 1;
	}
	message_vision("$N深吸了一口气，慢慢沿着洞壁往外爬。\n", me);
	me->move(__DIR__"gudi2");
	return 1;
}
