// Room: xiaoting.c
// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "小厅");
	set("long",@LONG
这是一个小小的客厅，墙上挂着一些字画，其中最显眼的是王
羲之的一幅《兰亭集序》，有个女仆人正在打扫着卫生。
LONG
	);
	set("exits", ([
		"south" : __DIR__"xiaoyuan",
                "up" : __DIR__"xiaolou",
	]));
        set("objects", ([
                 __DIR__"npc/afeng" : 1,
	]));
	set("item_desc", ([
		"《兰亭集序》" : "这大概是王老先生的真迹，笔法遒劲，浑然一派大家风范。\n" ,
	]));
	set("coor/x", 1620);
	set("coor/y", -1770);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_enter", "enter");
//	add_action("do_move", "open");
	add_action("do_kneel", "kneel");
}
int do_kneel(string arg)
{
        object me,hole;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="《兰亭集序》" ) {
		message_vision("$N虔诚地跪在《兰亭集序》下，磕起头来，“咚咚”地板好象是空的。\n", this_player());
	}
	if( sscanf(arg, "《兰亭集序》 %s", dir)==1 ) 
	{
		if( dir=="9" || dir=="nine")
		{
			if(!objectp(present("hole", environment(me))))
			{
message_vision("$N一口气磕了九个响头，突然间，地板松动了，露出一个大洞。\n",me);
				hole = new("/d/shiliang/obj/hole");
				hole->move("/d/shiliang/xiaoting");
			}
	        }   
		else return notify_fail("你胡乱磕了几个头，结果啥也没发生。\n");
	}		
	return 1;
}
int do_enter(string arg)
{
	if( !arg || arg!="floor" ) return 0;
		return notify_fail(" 想穿地板啊？你不会奇门遁甲。\n");
	return 1;
}