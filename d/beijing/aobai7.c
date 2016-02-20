// /d/beijing/aobai7.c
// Last Modified by winder on Jan. 18 2002

#include <room.h>
inherit ROOM;

void close_gate();
int do_unlock(string arg);

void create()
{
	set("short", "鳌拜书房");
	set("long", @LONG
这里是鳌拜书房，却没有一本书。各种古玩琳琅满目，商周青铜、汉瓦
当、唐三彩，珍珠宝石，应有尽有，只要拥有一件，就够你吃一辈子了。北
面墙上有一副画。书桌上有一本书。
LONG );
	set("item_desc", ([
		"picture" : "\n这张画很一般，不知为什么挂在这儿。\n",
		"book" : "\n这就是那本害得庄允城家破人亡的《明史辑略》。\n",
	]));
	set("exits", ([
		"south" : __DIR__"aobai4",
	]));
	set("objects", ([
		__DIR__"obj/picture" : 1,
		__DIR__"obj/bookming" : 1,
	]));
	set("coor/x", -202);
	set("coor/y", 4051);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	add_action("do_unlock", "open");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"aobai9")) )
        room = load_object(__DIR__"aobai9");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision","只听乒地一声，暗门自动关上了。\n",
            this_object());
        message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,
			this_object());
        room->delete("exits/south");
        message("vision","只听乒地一声，暗门自动关了起来。\n", room);
        message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,
			room );
     }
}


int do_unlock(string arg)
{
	object ob,room;
	if (query("exits/north"))
		return notify_fail("暗门已经是打开的。\n");
	if (!arg || (arg != "door"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("anmenkey", this_player())))
		return notify_fail("你不会撬锁。\n");
	message_vision(
	"$N用一把钥匙打开了秘门，可是钥匙却断了.\n", this_player());
	destruct(ob);
	if (this_player()->query_temp("doorisok"))        
        {
	set("exits/north", __DIR__"aobai9");
	if(!( room = find_object(__DIR__"aobai9")) )
        room = load_object(__DIR__"aobai9");
	if(objectp(room))
    	{
        set("exits/north", __DIR__"aobai9");
        message_vision("$N轻轻地推门，只听吱地一声，门开了。\n",this_player());
        room->set("exits/south", __FILE__);
        message("vision","只听吱地一声，暗门从外面打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
    	}
        this_player()->set_temp("doorisok",0);
        } 
	return 1;
}
