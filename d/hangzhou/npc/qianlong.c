// qianlong.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("乾隆皇帝", ({ "qianlong", "emperor"}) );
	set("title", "清高宗");
	set("gender", "男性");
	set("age", 43);
	set("per", 24);
	set("no_get", 1);
	set("long",
"乾隆皇帝姓爱新觉罗，名弘历，是大清入关后第四位在位皇帝，生平
号称有十大武功，自称“十全老人”。\n");
	set("combat_exp", 500);
	set("attitude", "piece");
	setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 30);
}
void init()
{
        add_action("do_kneel", "kneel");
}

int do_kneel()
{
	int i;
        object *chen, me = this_player();

        if ( objectp(present("chen jialuo", environment(me))))
        {
              message_vision(
"$N正想给乾隆皇帝请安，却被陈家洛一把拦住：鞑子的鹰犬，
不要脸的奴才，纳命来吧！\n\n", me);
              chen = all_inventory(environment(me));
              for(i=0; i<sizeof(chen); i++)
              {
                   if( chen[i] -> query("id") == "chen jialuo")
                       chen[i]->kill_ob(me);
              }
        }
        message_vision(
"$N恭恭敬敬地跪了下来，磕头道：奴才"+me->query("name")+"救驾来迟，皇上恕奴才死罪！\n\n", me);
        if( me->query("combat_exp") < 150000 )
        {
              message_vision(
"$n看着$N，哼了一声：你胆敢欺君冒功！凭你这点能耐也想挑了红花会？！\n\n", me, this_object() );
              message_vision(
"$n飞起一脚，踢得$N丫手丫脚滚下六和塔去了。\n\n", me, this_object() );
              me->move("/d/hangzhou/liuheta");
              tell_object(me, HIR"你从塔顶被一脚踢了下来，好疼！还受了伤。\n"NOR);
message("vision", HIR"只见" + me->query("name") + "从塔顶上扑通一声跌了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
              me->receive_wound("qi", 20);
              me->add("combat_exp", 0 - me->query("combat_exp") /100);
              return 1;
        }
        if( me->query("marks/qianlong") )
        {
              message_vision(
"$n看着$N，哼了一声，没理$N。\n\n", me, this_object() );
        }
        else
        {
              message_vision(
"$n看着$N说道：免了！看在你救驾有功，免你死罪，朕自有封赏。\n\n", me, this_object() );
              me->set("marks/qianlong", "1");
              me->add("combat_exp", 10000);
        }
        return 1;
}

