// Room: /d/huijiang/chufang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short","厨房");
	set("long",@LONG
这是红花会的厨房。红花会数万会众归隐回疆后，这个大厨房就
一直十分忙碌。厨房的大师傅都是来自苏杭，所以，饮食一如江南。
如果你饿了或渴了，可以向大师傅要(serve) 些吃的喝的。大师傅也
卖些江南的小点，注意留神一下墙上每天的告示(gaoshi)就好了。
LONG );
        set("objects", ([
		__DIR__"npc/shifu"     : 1,
        ]));
	set("exits", ([
		"south" : __DIR__"zoulang3",
	]));
	set("item_desc", ([
		"gaoshi" : 
"西湖醋鱼(Fish)           ：一两白银又二十文铜板
龙井虾仁(Shrimp)         ：五十文铜板
叫化童鸡(Chicken)        ：一两白银又二十文铜板
桂花鲜栗羹(Guihua geng)  ：一两白银又二十文铜板
酒瓶(Jiuping)            ：十六两白银\n"
	]));

	set("ricewater", 8);
	set("no_fight", 1);
	set("coor/x", -50050);
	set("coor/y", 9150);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("baozi", me))
	return notify_fail("大师傅瞪了你一眼: 吃不了要兜着走啊？\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
	if (me->query("family/family_name") != "红花会")
		return notify_fail("大师傅道：你不是红花会弟子，不能拿取食物。\n");
        if(present("baozi",this_player()) ) 
		return notify_fail("大师傅道：吃完了再拿，别浪费食物。\n");
        if(present("baozi",this_object()) ) 
		return notify_fail("大师傅道：吃完了再拿，别浪费食物。\n");
	if (query("ricewater")>0)
	{
		message_vision("大师傅连声答应，给$N一碟百果油包和一碗荷叶冬笋汤。\n",me);
		food=new("/d/hangzhou/npc/obj/baozi");
		water=new("/d/suzhou/npc/obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("大师傅对$N歉声道: 嗨，吃的喝的都没了。\n",me);
	return 1; 
}
