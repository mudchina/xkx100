//ROOM: /d/yanziwu/lanyue.c

inherit ROOM;

void init();
int do_knock(string);
int do_say(string);
void reset();
void close(object);

void create()
{
	set("short", "揽月居");
	set("long",@LONG
这是慕容公子的卧室，房中陈设普通，收拾得颇为整洁，屋角一架
茂兰盆景(penjing)长得很是旺盛。晚上月光从窗户射进来，满室银光，
是燕子坞的一大美景。
LONG );
	set("exits", ([
		"west": __DIR__"shuwu",
	]));

	set("item_desc", ([
		"penjing":"这盆景似乎很平常，独有边沿特别光滑。敲一敲试试？\n",
	]));
	set("objects", ([
		CLASS_D("murong")+"/murong-fu" : 1,
	]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("coor/x", 830);
	set("coor/y", -1550);
	set("coor/z", 10);
	setup();
	"/clone/board/murong_b"->foo();
}
void init()
{
	add_action("do_knock","knock");
	add_action("do_say","say");
}
int do_knock(string arg)
{
	object me;
	me=this_player();

	if (!arg || (arg!="penjing" ) )
		return notify_fail("你要敲什么？\n");

	set_temp("marks/pen",1);
	message_vision("$N突然在盆景上敲了几下，$N干吗呀。\n",me);
	tell_object(me,"你好象听见东面有说话的声音，可是东面什么都没有啊？！这何从说起呢？\n");
	return 1;
}
int do_say(string arg)
{
	object me;
	me = this_player();

	if (!query_temp("marks/pen")) return 0;
	if( !arg || arg=="" ) return 0;

	if(arg == "光复大燕")
	{
		tell_object(me,"你既然知道暗号，看来是公子叫你来的，就进来吧。\n");
		message("vision", "盆景边上的一堵墙渐渐移开，露出道木门。\n", this_player());
		set("exits/east", __DIR__"huanshi");
		remove_call_out("close");
		call_out("close", 5, this_object());
		return 1;
	}
}

void close(object room)
{
	message("vision","忽然一道人影闪过，将木门关上了。\n", room);
	room->delete("exits/east");
}
void reset()
{
	::reset();
	delete_temp("marks/pen");
}