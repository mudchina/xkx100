// Room: /d/guiyun/zhongting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

string look_xiao();
string look_zishi();

void create()
{
	set("short","中厅");
	set("long",@LONG
这是归云庄的中厅。庄中的大事以及召集弟子训话都是在这里进行
的。由于修建年代久远，看起来已颇为陈旧，但打扫得十分干净，光线
也较为充足，完全没有陈年旧宅的阴晦之气。四壁挂着一些古人书画精
品，皆为上乘之作，显得主人眼光不凡，胸中大有丘壑。
    靠里面是一张太师椅，椅后的墙上挂着一幅画(hua)。
LONG );
	set("objects",([
		__DIR__"npc/kezhene" : 1,
		__DIR__"npc/zhucong" : 1,
		__DIR__"npc/hanbaoju" : 1,
		__DIR__"npc/nanxiren" : 1,
		__DIR__"npc/zhangasheng" : 1,
		__DIR__"npc/quanjinfa" : 1,
		__DIR__"npc/hanxiaoying" : 1,
		__DIR__"npc/guanjia" :     1,
		__DIR__"npc/zhuangding3" : 1,
	]));  
	set("exits",([
		"east"  : __DIR__"qianting",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"zoulang4",
	]) );
	set("item_desc", ([
		"hua" :  "画中是一位形貌清矍的青衫老者，正在吹箫(xiao)，但是他的姿势(zishi)却有点奇怪。\n",
		"xiao" : (: look_xiao :),
		"zishi" : (: look_zishi :),
	]) );

	set("no_clean_up",0);
	setup();
}

string look_xiao()
{
        object me = this_player();

	if (!me->query_temp("guiyun_hua")) return "画中老人拿箫的姿势甚是怪异！\n";
	me->set_temp("guiyun_hua", 2);
	return "原来画中老人竟是把手中握着的箫当作了剑来舞。\n";
}

string look_zishi()
{
        object me = this_player();
	int level, exp;

	level = me->query_skill("sword", 1);
	exp = me->query("combat_exp");
	if (me->query_temp("guiyun_hua") < 2)
	{
		me->set_temp("guiyun_hua", 1);
		return "你仔细地端详着画中老人的身姿，恍惚间仿佛看见老人正在缓缓舞动着什么。\n";
	}
	else
	{
		write("原来画中老人舞箫的姿势里竟然暗藏着高深的剑法！\n");
		if (me->is_busy())
		{
			write("可惜你现在正忙着做别的事，无法专心研究这幅画。\n");
			return "";
		}
		if( me->is_fighting() ) {
			write("可惜你现在正在战斗中，无法专心研究这幅画。\n");
			return "";
		}
		if (me->query("jing") < 30) 
			return "可惜你太累了，无法集中精神来研究这幅画。\n";
		if (me->query_skill("sword", 1) > 100) 
			return "这幅在以前的你看来很艰深的画对现在的你而言已经没有什么可值得研究的了。\n";
		if ((int)me->query_skill("sword", 1) < 30 )
			return "你努力试图从画中老人的身姿里看出些什么，却发现一切都是徒劳的。\n";
	
		me->receive_damage("jing", 25);
		if( level * level * level /10 < exp)
			me->improve_skill("sword", me->query("int"));

		write("你仔细端详着画中老人舞箫的身姿。\n");
		if (!random(8))
			tell_room(this_object(), me->name() + "仔细端详着画中老人舞箫的身姿。\n", ({me}));
		return "你对剑法运用的微妙之处有了进一步的认识。\n";
	}
}

