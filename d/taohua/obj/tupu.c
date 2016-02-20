// tupu.c

inherit ITEM;

void create()
{
        set_name("九宫八卦图谱", ({ "tupu", "book", "shu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("long", "
九宫歌诀：九宫之义，法以灵龟。二四为肩，六八为足；左三右七，戴九履一；五居中间。
八卦图解：乾三连，坤六段；离中虚，坎中满；震仰盂，艮覆碗；兑上缺，巽下断。
五行相生：金生水，水生木，木生火，火生土，土生金。
五行相克：金克木，木克土，土克水，水克火，火克金。
");
		set("value", 20);
        	set_weight(10);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-wuxing",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"min_skill":	20,	// the minimum level you need before study
			"max_skill":	50	// the maximum level you can learn
		]) );
        }
        setup();
}

