// Room: /d/wudujiao/liandu.c

inherit ROOM;

void create()
{
	set("short", "练毒室");
	set("long", @LONG
这里是五毒教弟子专门的练毒室，可以在这里练制各种毒药，案上
摆着各式各样的器具。屋内正中放着一个一人多高的丹炉，炉火正旺，
有一个黑瘦的道人正手持桃木剑绕炉疾走，嘴里呐呐自语不知在念些什
么？
LONG
	);

	set("exits", ([
		"north" : __DIR__"nanyuan",
	]));
	set("objects", ([
		__DIR__"npc/daoren": 1,
	]));
	set("coor/x", -44920);
	set("coor/y", -81070);
	set("coor/z", 30);
	setup();
}

void init ()
{
	add_action("do_lianzhi","lianzhi");
}

int do_lianzhi (string arg)
{
	object ob;
	object me = this_player();
	if (arg != "red yao"&& arg!="yellow yao" && arg!="green yao" &&
		arg!="white yao"&& arg!="black yao" && arg!="shenxiandao")
		return 0;
	if (arg == "red yao")
	{
		if (!present("she dunang",me)||!present("shexin zi",me))
			return notify_fail("你身上药品不全，无法练制。\n");
		destruct(present("she dunang",me));
		destruct(present("shexin zi",me));
		ob = new("/clone/medicine/poison/redyao");
		ob->move(me);
		message_vision ("$N将身上的药品投入丹炉，按秘法小心练制起来！\n",me);
		tell_object(me, "药品练制成功！\n");
	}
	if (arg == "yellow yao")
	{
		if (!present("wugong dunang",me)||!present("chuanxin lian",me))
			return notify_fail("你身上药品不全，无法练制。\n");
		destruct(present("wugong dunang",me));
		destruct(present("chuanxin lian",me));
		ob = new("/clone/medicine/poison/yellowyao");
		ob->move(me);
		message_vision ("$N将身上的药品投入丹炉，按秘法小心练制起来！\n",me);
		tell_object(me, "药品练制成功！\n");
	}
	if (arg == "green yao")
	{
		if (!present("zhizhu dunang",me)||!present("fugu cao",me))
			return notify_fail("你身上药品不全，无法练制。\n");
		destruct(present("zhizhu dunang",me));
		destruct(present("fugu cao",me));
		ob = new("/clone/medicine/poison/greenyao");
		ob->move(me);
		message_vision ("$N将身上的药品投入丹炉，按秘法小心练制起来！\n",me);
		tell_object(me, "药品练制成功！\n");
	}
	if (arg == "white yao")
	{
		if (!present("xiezi dunang",me)||!present("heding hong",me))
			return notify_fail("你身上药品不全，无法练制。\n");
		destruct(present("xiezi dunang",me));
		destruct(present("heding hong",me));
		ob = new("/clone/medicine/poison/whiteyao");
		ob->move(me);
		message_vision ("$N将身上的药品投入丹炉，按秘法小心练制起来！\n",me);
		tell_object(me, "药品练制成功！\n");
	}
	if (arg == "black yao")
	{
		if (!present("chanchu dunang",me)||!present("duanchang cao",me))
			return notify_fail("你身上药品不全，无法练制。\n");
		destruct(present("chanchu dunang",me));
		destruct(present("duanchang cao",me));
		ob = new("/clone/medicine/poison/blackyao");
		ob->move(me);
		message_vision ("$N将身上的药品投入丹炉，按秘法小心练制起来！\n",me);
		tell_object(me, "药品练制成功！\n");
	}
	if (arg == "shenxiandao")
	{
		if (!present("jinshe duye",me)||!present("qianri zui",me))
			return notify_fail("你身上药品不全，无法练制。\n");
		destruct(present("jinshe duye",me));
		destruct(present("qianri zui",me));
		ob = new("/clone/medicine/poison/shenxiandao");
		ob->move(me);
		message_vision ("$N将身上的药品投入丹炉，按秘法小心练制起来！\n",me);
		tell_object(me, "药品练制成功！\n");
	}
	return 1;
}
