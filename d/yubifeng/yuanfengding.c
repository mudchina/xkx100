// /yubifeng/yuanfengding.c
// Last modified by winder 2003.9.2

int do_stamp(string arg);

inherit ROOM;

void create()
{
	set("short", "圆峰顶");
	set("long", @LONG
峰顶积满了千百年来从未消融的坚冰，历年新雪，层层叠叠。远望
四周，群峰在上，峰谷间寒风贯穿，嘶声凌厉。峰顶正中，有一个微陷
的小窝。
LONG );
	set("exits", ([
		"northdown" : __DIR__"yuanfeng",
	]));
	set("objects", ([
		__DIR__"npc/tong1" : 1,
		__DIR__"npc/tong2" : 1,
	]));
	set("outdoors", "yubifeng");
	set("coor/x", 6100);
	set("coor/y", 5120);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_stamp","stamp");
	add_action("do_stamp","tread");
	add_action("do_stamp","cai");
	add_action("do_stamp","ta");
}

int do_stamp(string arg)
{
	object me = this_player();
	int n;

	n = me->query_skill("force", 1);

	if ( !arg || (arg != "wo" && arg != "xiaowo"))
	{
		write("你要踩踏什么呀？\n");
		return 1;
	}
	if(n > 100 && me->query("qi") > 1000)
	{
		message_vision("$N深吸了一口气，看准了方位，一步步走将过去。\n...\n待走到圆峰之顶的窝儿正中，用力踩踏，果然脚下松动，身子下落。\n...\n$N早有防备，双足着地，立即幌亮火摺，拨开冰雪，见前面是条长长的通道。\n",me);
		me->move(__DIR__"tongdao1");
	}
	else
	{
		message_vision("$N在峰顶踩来踏去，踢得冰屑雪花溅飞，结果全无动静。\n", me);
		me->receive_damage("qi",10);
	}
	return 1;
}
