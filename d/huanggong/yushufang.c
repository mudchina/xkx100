// Room: /d/huanggong/yushufang.c
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);
void create()
{
	set("short", "御书房");
	set("long", @LONG
皇上用功读书的御书房，又叫上书房、南书房。也是皇子皇孙们读
书的地方。北面是圣祖御笔的牌匾(bian)，两侧是世宗御笔楹联(lian)。
四下齐整地排着几张书架，上面看来都是些名典巨著。你暗自想，原来
皇帝也读这么多的书啊。书房正中有张精雕的檀香木书桌，桌上摆着几
本封面精美的书。
LONG 	);
 	set("item_desc", ([ 
		"bian" : "\n养正毓德\n\n",
		"lian" : "
立身以至诚为本
读书以明理为先\n\n",
 	]));
	set("objects", ([
		__DIR__"npc/kangxi" : 1,
		"/d/beijing/obj/book14_2" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"qianqinggong",
	]));

	set("coor/x", -190);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"mishi")) )
	room = load_object(__DIR__"mishi");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","只听乒地一声，暗门自动关上了。\n", this_object());
		message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n", this_object());
		room->delete("exits/south");
		message("vision","只听乒地一声，暗门自动关了起来。\n", room);
		message("vision","你脑海中闪过一个念头：坏了！出不去了！\n", room );
	}
}


int do_open(string arg)
{
	object ob,room;
	if (query("exits/north"))
		return notify_fail("暗门已经是打开的。\n");
	if (!arg || (arg != "bian"))
		return notify_fail("你要打开什么？\n");
	set("exits/north", __DIR__"mishi");
	if(!( room = find_object(__DIR__"mishi")) )
		room = load_object(__DIR__"mishi");
	if(objectp(room))
	{
		set("exits/north", __DIR__"mishi");
		message_vision("$N轻轻地推了推牌匾，只听吱地一声，一个暗门开了。\n",this_player());
		room->set("exits/south", __FILE__);
		message("vision","只听吱地一声，暗门从外面打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
