// Room: /d/songshan/chufang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是嵩山派的厨房，一位油光满面的伙夫正在烧火做饭。房间里散
发着饭菜的香味。厨房里放着几张小桌椅，你可以向伙夫要(serve) 些
吃的喝的。
LONG);
	set("exits",([
		"east" : __DIR__"westting",
	]));
	set("no_clean_up", 0);
	set("ricewater", 5);
	set("no_fight","1");
	set("coor/x", -50);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
		return notify_fail("你一转身，发现门口贴着张告示：“饮食不外带”。\n");
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
	if (me->query("family/family_name") != "嵩山派")
		return notify_fail("伙夫把手一摊：“你不是嵩山派弟子，不能拿取食物。”\n");
        if(present("rice",this_player()) ) 
		return notify_fail("伙夫一瞪牛眼：“吃完了再拿，别浪费食物！”\n");
        if(present("rice",this_object()) ) 
		return notify_fail("伙夫看了看桌上，道：“吃完了再拿，别浪费食物。”\n");
	if (query("ricewater")>0)
	{
		message_vision("伙夫连声答应，给$N一碗黄米饭和一碗鲜菇汤。\n",me);
		food=new("/d/huashan/obj/rice");
		water=new("/d/huashan/obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("伙夫对$N歉声道：“嗨，吃的喝的都没了。”\n",me);
	return 1; 
}
