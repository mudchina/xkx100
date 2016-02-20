// Feb. 6, 1999 by Winder
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name("金蛇剑谱", ({ "jinshe jianpu", "jianpu"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这就是记载着金蛇郎君一生心血的金蛇剑谱。\n");
                set("value", 50000);
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set("no_put", "这本剑谱不能放进去。\n");
        }
}
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int jslevel; 
        int neili_lost;
        if (!(arg=="jinshe jianpu" || arg == "jianpu" ))
        return 0;
        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }
/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("你要读什么？\n");
                return 1;
        }
*/
        if (!id(arg)) { 
                write("你要读什么？\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }
        switch(random(3)) {
          case 0:
        message("vision", me->name() + "专心地研读金蛇剑谱。\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "看着金蛇剑谱，眼中好象发着阵阵金光。\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "突然放下剑谱，站起身来比划了几下。\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 15 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
        if ( me->query_skill("jinshe-jian", 1) > 84) neili_lost = 55;
        else
        if ( me->query_skill("jinshe-jian", 1) > 74) neili_lost = 40;
        else neili_lost = 5;
        if( (int)me->query("neili") < neili_lost) {
                write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }
        jslevel = me->query_skill("jinshe-jian", 1);
        if( (int)me->query("combat_exp") < (int)jslevel*jslevel*jslevel/10 ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        } 
        if( me->query_skill("jinshe-jian", 1) > 200){
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }
        me->receive_damage("jing", 45);
        me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("jinshe-jian", (int)me->query_skill("literate", 1)/3+1);
        write("你研读《金蛇剑谱》的秘诀，眼中发出阵阵金光，颇有心得。\n");
        return 1;
}
