// Room: /d/yanziwu/tingyu.c
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", "听雨居");
	set("long", @LONG
这个小居建在湖上，看上去没有什么特别之处。四面为水，湖上烟
波尽收眼底。唯一奇怪的是这儿放着一具瑶琴(qin)。
LONG );
	set("item_desc", ([
	    "qin" : "这琴比之寻常七弦琴短了尺许，却有九根琴弦。\n"
		     "不知是该去弹一弹(tan)还是将它击开(break)。\n",
	]));
	set("objects", ([
	    __DIR__"obj/shigu"   : 1,
	    __DIR__"obj/xianglu" : 1,
	]));
	set("exits", ([
	    "south" : __DIR__"xiaoqiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1480);
	set("coor/z", 10);
	setup();
}


void init()
{
	add_action("do_tan", "tan");
	add_action("do_tan","play");
	add_action("do_break","break");
}

int do_tan (string arg)
{
	object room;
	object ob = this_player();
	if (!arg||arg!="qin") return notify_fail("你要弹什么？\n");
	message_vision("$N轻轻的在琴上一拨，铛的一声，声音颇为宏亮。\n\n"
		+"似乎这琴有点古怪.....\n"
		+"$N正纳闷间，忽觉脚底一虚，身子往下直沉.....\n", ob );
	tell_object(ob, "\n你忍不住啊哟一声，便掉入了一个软绵绵的所在！原来是一艘小船。\n\n" ) ;
	room=load_object("d/yanziwu/hu");
	ob->move(room) ;

	call_out("mantuo", 10 , ob );
	return 1 ;
}

int do_break(string arg)
{
	if (!arg||arg!="qin") return notify_fail("你要击开什么？\n");
	message_vision(
		"\n$N一掌击开瑶琴，只听“唰”的一声,突然银光一闪，\n"+
		"一枚梅花镖倏的射出,“噗”的一声射入了$N的人中穴。\n", this_player());
	if((int)this_player()->query("qi")<200) this_player()->die();
	else this_player()->unconcious();
	return 1;
}

int mantuo( object ob )
{
	if (ob->query("family/family_name") == "姑苏慕容")
	{
		tell_object(ob, "\n小船转过一排"HIG"垂柳"NOR"，远远看见"HIC"水边"NOR"一丛"HIR"花树"HIM"映水而红，灿若云霞"NOR"。\n你不禁“啊”的一声低呼。茫然的看看四周，走下船来。\n\n") ;
		ob -> move (__DIR__"chalin");
	}
	else
		ob -> move (__DIR__"hupan");
	return 1;
}