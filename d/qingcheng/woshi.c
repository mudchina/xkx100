// woshi.c

inherit ROOM;
int do_open(string arg);

void create()
{
	set("short", "卧室");
	set("long", @LONG
这里是余沧海的寝室。余沧海虽然是道家弟子，可也不禁婚约。因
此他娶了正配，还一气陪进来好几个小妾。卧室中摆着一张楠木花雕大
床，一具红松大衣柜，柜顶搁着几只牛皮藤箱子，墙角立着一张有点陈
旧的梳妆台 (tai)，靠窗(window)处是一张花梨木书桌。
LONG
	);
	set("key", 1);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"garden",
	]));
        set("item_desc", ([
		"window" : "窗外就是天下幽的青城了。\n",
		"tai"    : "一张红漆镶玉边的半开的梳妆台。\n",
        ]));
	set("objects", ([
		__DIR__"npc/yuwife" : 1,
	])  ) ;

	set("coor/x", -8070);
	set("coor/y", -820);
	set("coor/z", 90);
	setup();
}
void init()
{
        add_action("do_open", "open");
        add_action("do_open", "kai");
}

int do_open(string arg)
{
	object key, me=this_player();

        if( !arg || arg!="tai" ) return 0;

        if( arg=="tai" )
	{
		if ((me->query("family/master_id") !="yu canghai") &&
			objectp(present("yu wife", environment(me))))
		{
			return notify_fail(
"余小星喝道：这位" + RANK_D->query_respect(me) + "，你不能随便翻人家东西。\n");
			return 1;
		}
		if (query("key"))
		{
			message_vision(
"$N轻轻的打开梳妆台抽屉，发现里面有一支铁钥匙。\n", me);
			key = new(__DIR__"obj/key2");
			key->move(__FILE__);
			set("key", 0);
			return 1;
		}
		message_vision(
"$N轻轻的拉开抽屉，可是里面啥都没有...。\n", me);
		return 1;
	}
	return 0;
}