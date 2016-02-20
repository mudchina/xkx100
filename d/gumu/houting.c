// Room: /d/gumu/houting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @LONG
厅上也是空荡荡的没什么摆设，正前方写着一行大字（zi），东西
两壁都挂着一幅画。西首 (westpic)的画像是两个女郎，正是古墓派的
师尊林朝英和师祖婆婆的肖像，东侧 (eastpic)画像中却是一个道士。 
    西面可以看到有一扇暗门(door)。
LONG	);

	set("exits", ([
		"east"  : __DIR__"mudao18",
//		"west"  : __DIR__"mudao06",
		"north" : __DIR__"mudao07",
		"south" : __DIR__"mudao19",
	]));
	set("count", 1);
	set("item_desc", ([
		"door" : "一扇厚重的石门，光溜溜的全没有把手。你认真看了看，发现门边的石壁上似乎有什么按钮(niu)可以开门。\n",
		"westpic" : HIM"画中两个姑娘，一个二十五六岁，正在对镜梳妆，画中镜里映出女郎容貌极美，秀眉入鬓，眼角却隐隐带着一层杀气，正是古墓派师尊林朝英。另一个是十五六岁的丫鬟，手持面盆，在旁伺候，憨态可掬，满脸稚气，后来便成了小龙女
的师傅。\n"NOR,
		"eastpic" : HIC"像中道人身材甚高，腰悬长剑，右手食指指着东北角，只是背脊向外，面貌却看不见。\n"NOR,
		"zi" : HIR"\t入我古墓，先唾重阳，欲成神功，拜我祖师。\n"NOR,
	]));
	set("coor/x", -3180);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{ 
	add_action("do_ketou", "ketou"); 
	add_action("do_tuo", "tuo");
	add_action("do_an", "press");
	add_action("do_an", "an");
}
 
int do_ketou(string arg)
{
	mapping fam;
	object me = this_player();

	if ((!arg) || (arg != "westpic")) return 0;
		message_vision("$N向西跪倒，双膝及地，恭恭敬敬向祖师婆婆的画像磕了一个响头。\n", me);
	me->add_temp("marks/ketou", 1);
	me->receive_damage("qi", 5);
	if(me->query_temp("marks/tuo") == 2 &&
		me->query_temp("marks/ketou") == 4 &&
		(!(fam = me->query("family")) ||
		fam["family_name"] != "古墓派") &&
		me->query("combat_exp") < 10000)
	{
		me->set("family_name", "古墓派");
		me->set("title", HIW"古墓传人"NOR);
		me->create_family("古墓派", 5, "传人");
		me->set("class","swordsman");
		write(HIR"恭喜你自愿成为一名古墓弟子。\n"NOR);
		me->delete_temp("marks/tuo");
		me->delete_temp("marks/ketou");
		return 1;
	}
	if (me->query_temp("marks/ketou") == 15 )
	{
		me->delete_temp("marks/ketou");
		if (query("count") == 0)
			return notify_fail("地上露出一方小孔，但里面空空如也，想必有人先你下手了。 \n");
		message_vision(HIY "$N面前的石地突然下沉，露出一把金钥匙，$N把它捡了起来。\n"NOR, me);
		set("count", 0);
		new(__DIR__"obj/goldkey")->move(me);
	}
	return 1;
}

int do_tuo(string arg)
{
	object me = this_player();

	me->receive_damage("qi", 5);
	if (me->query_temp("marks/tuo") == 2)
		return notify_fail("你唾够了没有？\n");
	if ( arg=="eastpic")
	{
		message_vision("$N朝王重阳的画像狠狠唾了一口。\n", me);
		me->add_temp("marks/tuo", 1);
		return 1;
	}
	return notify_fail("你不要随便乱唾口水啊！\n");
}

int do_an(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "niu" )
	{
		message_vision("你在石壁上乱按一气，除了一手灰，啥也没摸着。\n", me);
		return 1;
	}
	if( query("exits/west"))
	{
		return notify_fail("石门已经是开着的，你还按个啥？\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$N站在石门前，也不知在哪里按了一下，石门吱吱响着，缓缓打开了。\n", me);
		if( !(room = find_object(__DIR__"mudao06")) )
			room = load_object(__DIR__"mudao06");
		set("exits/west", __DIR__"mudao06");
		room->set("exits/east", __DIR__"houting");
		tell_room(room,"只听得石门在吱吱声中被缓缓打开。\n");
		remove_call_out("close");
		call_out("close", 5, me);
	}
	else
		message_vision("$N试着在石壁上按来按去，可是石门纹丝不动，只得罢了。\n", me);
	return 1;
}

void close(object me)
{
	object room;

	tell_room(this_object(), "石门缓缓地关上，恢复了原状。\n");
	delete("exits/west");
	if( !(room = find_object(__DIR__"mudao06")) )
		room = load_object(__DIR__"mudao06");
	room->delete("exits/east");
	tell_room(room,"东墙的暗门缓缓地关上了。\n");
}
