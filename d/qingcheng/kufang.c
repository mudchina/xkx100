// Room: /d/qingcheng/kufang.c

inherit ROOM;
int do_qiao(string arg);

void create()
{
	set("short", "库房");
	set("long", @LONG
这里是青城一派的库房，收藏着各种途径得来的珍宝。库房北边壁
上柜挂着一些白章虎皮、花格豹皮和其它不知名的皮毛，南边壁柜里摆
放着一些奇石和铜铁制品，看来还是值点钱的。东壁下是一个大铁箱，
锁得甚是严实。
LONG );
	set("objects", ([
		__DIR__"obj/xiang" : 1,
	]));
	set("coor/x", -8069);
	set("coor/y", -840);
	set("coor/z", 90);
	setup();
//	replace_program(ROOM);
}
int do_qiao(string arg)
{
	object me=this_player();
	object room;
	if (arg != "men") return 0;
	if(!( room = find_object(__DIR__"zoulang2")) )
		room = load_object(__DIR__"zoulang2");
	if(objectp(room))
	{
		set("exits/west", __DIR__"zoulang2");
		message_vision("$N费了半天劲，把门撬开了。\n",me);
		room->set("exits/east", __FILE__);
		message("vision","里面有人把库门打开了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
void init()
{
	add_action("do_qiao","qiao");
}
void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"zoulang2")) )
		room = load_object(__DIR__"zoulang2");
	if(objectp(room))
	{
		room->delete("exits/east");
		message("vision","只听乒地一声，库门自动关了起来。\n",room);
		message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n", room);
		delete("exits/west");
		message("vision","只听乒地一声，库门自动关了起来。\n",this_object());
		message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" , this_object());
	}
}