inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "金水桥");
        set("long",  @LONG
五座金水石桥横卧金水河上，中间那座桥是专供皇帝使用的，
称为＂御路桥＂，桥的柱头全为龙形，人称＂蟠龙柱＂。两边为王
公桥，桥的柱头雕成＂荷花柱＂。桥下是金水河缓缓的流水。水看
上去很清，据说曾有人在这里跳河 (out)。这里是进皇宫正门的必
经之路。
LONG);
        set("outdoors", "beijing");
        set("exits", ([
                "north" : __DIR__"zhengmen",
                "south" : __DIR__"tian_anm",
                "west" : __DIR__"bridge2",
                "east" : __DIR__"bridge3",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	int i, ging_cost, qi_cost;

	me = this_player();
	i = (int)me->query_skill("dodge", 1) + random(50);
	ging_cost = 300 / (int)me->query("int");
	qi_cost = 300 / (int)me->query("int");
	if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
		i = 0;

	message_vision("$N翻过石栏，一个纵身，跳了下去。\n", me);
	if ( i < 75)
		{
	        message_vision("一股潜流立刻把$N吞没了。\n", me);
		me->die();
	        }
	else if( i < 100)
		{
	        message_vision("一股潜流立刻把$N吞没了。\n", me);
		me->unconcious();
		switch( random(2) ) {
		case 0:
		me->move(__DIR__"bridge2");
			break;
		case 1:
		me->move(__DIR__"bridge3");
			break;
		message_vision("一股潜流把$N冲回岸边。\n", me);
		}
	        }
	else {
		switch( random(5) ) {
		case 0:
		message_vision("一股潜流把$N冲回岸边。\n", me);
		me->move(__DIR__"bridge2");
			break;
		case 1:
		message_vision("一股潜流把$N冲回岸边。\n", me);
		me->move(__DIR__"bridge3");
			break;
		case 2:
		case 3:
		case 4:
		message_vision("$N在水中昏昏沉沉地胡乱挣扎，突然之间触到了一面硬壁。\n", me);
		message_vision("$N恍若抓住了救命稻草，贴着滑溜溜的硬壁就浮出了水面。\n", me);
		message_vision("$N吐了一口水，抬头一看，原来身在一口井中。\n", me);
         	me->move("/d/huanggong/inwell");
		break;
		}
		if( (i > 125) && me->query_skill("dodge",1)<101)
			me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
	     }
	return 1;
}
