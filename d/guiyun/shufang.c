// Last Modified by winder on Jul. 9 2001
// Room: /d/guiyun/shufang.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是庄主平日读书的地方。进屋门楣上，歪歪斜斜嵌着一个铁八
卦 (gua)，看起来和房间不太相衬。屋中琳琅满目，全是诗文典籍；几
上桌上摆着许多铜器玉器，看来尽是古物。壁上挂着一幅水墨画(hua)。
房内另有一张竹榻，一位身材高大的中年人正坐在榻上。
LONG );
	set("exits", ([
		"west" : __DIR__"houting",
	]));
	set("item_desc",([
		"hua" : "
那上面画的是一个中年书生在月明之夜中庭伫立，手按剑柄，仰天长吁，神情寂寞。
画的左下角题着一首词：
“昨夜寒蛩不住鸣。惊回千里梦，已三更。起来独自绕阶行。人悄悄，帘外月胧明。
  白首为功名。旧山松竹老，阻归程。欲将心事付瑶筝，知音少，弦断有谁听？”
下款题着“五湖废人病中涂鸦”八字。\n"
	]) );
	set("no_fight", 1);
	set("guacount", 1);

	set("objects", ([
		CLASS_D("taohua")+"/lu" : 1,
		__DIR__"npc/shutong" : 1,
	]));

	setup();
}
void init()
{
	add_action("do_take","take");
}
int do_take(string arg)
{
	object obn, me = this_player();
	int n;

	n = this_player()->query_skill("dodge",1);
	if( !arg || arg != "gua" )
	{
		write("你要拿什么呀！\n");
		return 1;
	}
	message_vision("$N在门站定，深呼一口气，突然跃起。\n", me);
	if(n >= 80 && query("guacount") > 0)
	{
		message_vision("只见$N的身子在空中打了几个盘旋，身子轻飘飘落回，手中多了一物。\n", me);
		obn = new("/kungfu/class/taohua/obj/bagua");
		obn->move(me);
		add("guacount",-1);
	}
	else message_vision("$N定睛一看，发现八卦早被人拿走了。\n", me);
        return 1;
}
