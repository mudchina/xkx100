// Obj: /d/guiyun/obj/tuifa.c 旋风扫叶腿法
// Last Modified by winder on Jul. 9 2001

inherit ITEM;

void create()
{
	set_name("旋风扫叶腿图解", ({ "tuifa tujie", "tujie", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure", 1);
		set("unit", "本");
		set("long", "这本腿法中详细地画着黄药师所创的旋风扫叶腿的图解，虽然对你来说略显艰深，但用它来领悟基本腿法的诀窍却是可以的。\n");
		set("value", 40);
		set("material", "paper");
		set("skill", ([
			"name":	"leg",		// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
