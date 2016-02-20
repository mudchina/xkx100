// Room: /beijing/aobai8.c

#include <room.h>
inherit ROOM;

void close_gate();
int do_unlock(string arg);

void create()
{
	set("short", "牢房");
	set("long", @LONG
这是一个昏暗的房间，窗户都被钉死。地上放着皮鞭、木棍等刑具，显然
这是鳌拜私立公堂，审讯人犯的所在。一个书生被捆在墙上，鲜血淋漓，遍体
鳞伤。
LONG );
	set("objects", ([
		__DIR__"npc/zhuangyu" : 1,
	]));
	set("coor/x", -202);
	set("coor/y", 4049);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	add_action("do_unlock", "open");
}

void close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"aobai4")) )
        room = load_object(__DIR__"aobai4");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision","只听乒地一声，暗门自动关上了。\n",
            this_object());
        message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,
			this_object());
        room->delete("exits/south");
        message("vision","只听乒地一声，暗门自动关了起来。\n", room);
        message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,
			room );
     }
}


int do_unlock(string arg)
{
	object room;
	if (query("exits/north"))
		return notify_fail("暗门已经是打开的。\n");
	if (!arg || (arg != "men"))
		return notify_fail("你要打开什么？\n");
	message_vision(	"$N从里面打开了秘门。\n", this_player());
	set("exits/north", __DIR__"aobai4");
    if(!( room = find_object(__DIR__"aobai4")) )
        room = load_object(__DIR__"aobai4");
    if(objectp(room))
    {
        set("exits/north", __DIR__"aobai4");
        message_vision("$N轻轻地推门，只听吱地一声，门开了。\n",this_player());
        room->set("exits/south", __FILE__);
        message("vision","只听吱地一声，暗门从外面打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
    }
return 1;
}
