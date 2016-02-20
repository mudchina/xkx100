// room-su1.c 

inherit ROOM;
string look_sign(object me);

void create()
{
        set("short", "苏鲁克的家");
        set("long", @LONG
由于苏鲁克的妻子十年前被强盗害死，只剩下苏鲁克和他儿子苏普两
人，所以屋里乱七八糟的。但苏鲁克并不在意，因为他觉得象他这样的草
原汉子是不能去做女人们做的事情的。火堆一旁的大挂毯上挂着两两张精
致的羊毛毯子(tanzi)。
LONG
        );
        set("exits", ([
            "northeast" : __DIR__"shuijing",
            "east" : __DIR__"caoyuan7",
            "west" : __DIR__"caoyuan7",
            "south" : __DIR__"caoyuan7",
        ]));

        
set("item_desc", ([
		"tanzi": (: look_sign :),
	]) );
        set("objects", ([
                    __DIR__"npc/su" : 1,

        ]));

        setup();
//        replace_program(ROOM);
}
string look_sign(object me)
{
	if(me->query_skill("blade",1)<30 ) {
    return "  一张毛毯上织著一个大汉，挥舞长刀，正在和一头豹子搏斗，地上还有只
被砍翻了的豹子，远处一头豹子正挟著尾巴逃走。另一张毛毯上织著一个男孩，
刺死了一头大灰狼。那二人一大一小，都是威风凛凛，英姿飒爽。\n";
	} else {
	me->set_temp("su_tanzi",1);
	return "  一张毛毯上织著一个大汉，挥舞长刀，正在和一头豹子搏斗，地上还有只
被砍翻了的豹子，远处一头豹子正挟著尾巴逃走。另一张毛毯上织著一个男
孩，刺死了一头大灰狼。那二人一大一小，都是威风凛凛，英姿飒爽。你定
了定神，隐约感觉画里似乎隐藏着极为高明的刀法\n";
}
}

void init()
{
        add_action("do_wudao", "liandao");  
}

int do_wudao(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

    if (!me->query_temp("su_tanzi", 1)) return 0;

    if( !arg || arg!="tanzi" ) {
                write("你要根据什么练刀！\n");
                return 1;
        }
        if (!weapon || weapon->query("skill_type") != "blade" )
		return notify_fail("你手中无刀，怎么练？\n");

        if ((int)me->query_skill("blade", 1) >100 )
        return notify_fail("你已经竭尽全力去体会毯子上暗藏的刀法精要，但是无法再增长你的基本刀法了！\n");
    
	//    me->receive_damage("jingli", 10+random(15));
		me->receive_damage("jing",random(10));
        write("你对照着毯子上暗藏的刀法精义，挥舞长刀，渐渐地悟出了一些有关基本刀法的精要之所在。\n");
         me->improve_skill("blade", me->query("int"));       
         return 1;
}                                     
int valid_leave(object me, string dir)
{
	me->set_temp("su_tanzi", 0);
       return 1;
	 
}
