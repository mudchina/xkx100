// ouyezi.c
#include <ansi.h>
#include <command.h>
//inherit F_CLEAN_UP;
inherit NPC;

string *ouyezi_msg =({
GRN"欧冶子将一块"HIR"赤铜"GRN"和一块"HIC"青锡"GRN"塞进炼炉，拉起沉重的风箱，火焰\n",
GRN"贪婪吞噬了铜锡块。..当铜锡块通体透"HIR"红"GRN"时，欧冶子师傅将"BLK"黑铁"GRN"置入\n",
GRN"炉中，掺入"HIY"黄金"GRN"和"HIW"白银"GRN"。一会工夫，欧冶子用钢钳夹出五金块，猛地\n",
GRN"将它浸入一种无嗅无味的"BLK"黑色液体"GRN"中..唧！..\n",
GRN"随后..乒..乒..梆....梆....乒....乒...梆....梆...乒..梆....梆...乒...梆.....\n",
GRN"..哈....哈....哈....哈....欧冶子仰天长笑声震瓦铄，道：嘿..嘿.....\n\n",
GRN"宝剑有名方能传，你的宝剑该什么名(name)？!\n"NOR,
});

void create()
{
        set_name("欧冶子",({ "ou yezi","ou" }));
        set("gender", "男性" );
        set("age", 73);
        set("long",
"欧冶子是当世铸剑大师。他铸的剑锋利无比。可是你给的钱太少可也
不行。一分钱一分货么。\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("rank_info/respect", "欧冶师傅");
        set("inquiry", ([
            "造剑": "造剑，好说，十两黄金，款到交货！",
            "铸剑": "造剑，好说，十两黄金，款到交货！",
            "价格": "这个价格嘛...!嘿嘿,一律十两黄金起价，一分钱一分货么。",
         ]) );
        setup();
}
void init()
{
        object ob,me;
        add_action("do_name","name");
}
int accept_object(object me, object ob)
{
       if((int)me->query_temp("done_s",1))
       {
          say(
"欧冶子奇怪的看着"+ me->query("name")+"，道:你不是有自己的兵器吗？\n");
        return 0; }
        if( ob->query("money_id") && ob->value() >= 100000)
        {
        command("nod");
        command("say 好吧,"+me->query("name")+"我这就替你打造, 请稍等！\n");
        call_out( "ouyezi_stage", -10, me, 0 );
        (int)me->query_temp("marks/ouyezi");
        me->set_temp("marks/ouyezi",1);
        return 1;
        }
}
void ouyezi_stage(object ob, int stage)
{
        int i;
        object *inv;
        if( !ob || !present(ob) )
        return;
        tell_object(ob, ouyezi_msg[stage]);
        if( ++stage < sizeof(ouyezi_msg) ) {
        call_out( "ouyezi_stage", -10, ob, stage );
        return;}
}

int do_name(string arg,object ownsword)
{
        object me = this_player();
        if(!(int)me->query_temp("marks/ouyezi"))
        {
            return notify_fail("欧冶子气得一甩手：什么？和我老人家也赖？\n");
        }
        if( !arg ) return notify_fail
         ("欧冶子问道：宝剑有名方能传，你的宝剑该什么名(name)？可以问(ask)嘛！\n");
        if( strlen(arg) > 20 )
        return notify_fail("欧冶子说：哇拷！这么长怎么写得下，想个短一点的吧！\n");

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        ownsword= new(__DIR__"obj/ownsword");
        ownsword->set("name",arg +NOR);
        tell_object(me,
"只见欧冶子师傅抽出鱼肠剑，在宝剑上随手挥洒，立马就有了"+arg+NOR"几个\n");
        tell_object(me,
"龙飞凤舞的细字，直把你看得目瞪口呆。\n\n");
        command("smile");
        command("say 成了。" + me->query("name") +"，拿去吧！说完便递了一把剑
过来..\n\n");
        ownsword->move(me);
        write("你拿着剑端详一下，宝剑暗纹浮动，真是绝世无双的手艺。\n\n");
        (int)me->query_temp("done_s");
        me->set_temp("done_s",1);
        me->delete_temp("marks/ouyezi");
        return 1;
}

int do_ask(object me)
{
       me = this_player();
       if(!(int)me->query_temp("marks/ouyezi"))
       {
           return notify_fail("欧冶子道：你想铸宝剑吗？\n");
       }
       write(@HELP
欧冶子说道:我这门手艺叫做刻字( name <名称> ),
可以在宝剑上刻字，如果你想在你的兵器上刻下带色的字，剑以名传么。
那就要采用某种特殊工艺，你且听我慢慢说来:

$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色

我担保它永不褪色。
HELP
        );
        return 1;
}
