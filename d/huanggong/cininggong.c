// Room: /d/huanggong/cininggong.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "慈宁宫");
	set("long", @LONG
这是太后的寝宫。. 这里也是太后垂帘听政之处。曾经主宰天下数
十年的朝廷政令，就出自你所在的女主人之手。东西两面是暖阁。东暖
阁里是太后的雕花大床 (bed)。北面是个大佛堂，有清一代，太后除了
祭祀萨满，几乎无一例外地礼佛。
LONG
	);
	set("opened", 1);
	set("item_desc", ([
		"bed" : "太后老婊子的床，看什么看！\n",
	]));
	set("exits", ([
		"south" : __DIR__"ciningmen",
		"north" : __DIR__"dafotang",
	]));
	set("objects", ([
		__DIR__"npc/leichu" : 1,
		__DIR__"npc/dengbingchun" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 5271);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "dakai");
	add_action("do_open", "xiangkai");
}

int do_open(string arg)
{
	object me, obj;

	me = this_player();
	if( !arg || arg!="bed" )
              return notify_fail("你要打开什么？\n");
	message_vision(YEL
"$N掀开被褥，见床板上有个小铜环，伸指一拉，一块阔约一尺，长约
二尺的木板应手而起，下面是个长方形的暗格，赫然......\n" NOR,me);
	if ( query("opened") != 1)
	{
		message_vision(HIR"什么都没有！\n" NOR,me);
		return 1 ;
	}
	message_vision(HIY"放着三部经书！\n" NOR,me);
	obj = new("/d/beijing/obj/book14_3");
	obj -> move(this_object());
	obj = new("/d/beijing/obj/book14_4");
	obj -> move(this_object());
	obj = new("/d/beijing/obj/book14_6");
	obj -> move(this_object());
	add("opened", -1);
	return 1;
}
