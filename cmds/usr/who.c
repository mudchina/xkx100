// who.c
// From ES2
// Modified by Java on Sep.14 1998
// Commedted by Spacenet on Nov.4 1999
// Modified by Zeratul on Mar.26 2000
inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>


string *faction_name = ({
	"少林派",
	"南少林派",
	"武当派",
	"峨嵋派",
	"青城派",
	"昆仑派",
	"嵩山派",
	"泰山派",
	"华山派",
	"衡山派",
	"恒山派",
	"星宿派",
	"丐帮",
	"明教",
	"神龙教",
	"大理段家",
	"桃花岛",
	"白驼山派",
	"姑苏慕容",
	"全真教",
	"古墓派",
	"雪山寺",
	"逍遥派",
	"灵鹫宫",
	"凌霄城",
	"云龙门",
	"红花会",
	"黑木崖",
	"五毒教",
	"铁掌帮",
});
int sort_user(object,object);
int visiblep(object);
int help();

void create() {  seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string name, str, *option;
        object *list, *ob, ob1;
	int i, j, ppl_cnt, fac_no, fac_amt = sizeof(faction_name);
        int opt_long, opt_wiz, opt_party ,opt_age, opt_exp;

        if( arg ) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-h": return help();
                                case "-l": opt_long = 1;        break;
                                case "-w": opt_wiz = 1;         break;
//                              case "-f":
                                case "-p": opt_party = 1;       break;
                                case "-a": opt_age = 1;         break;
  //                              case "-e": opt_exp = 1;         break;
                                //如果不带以上几种参数，则为who + player_id情况
                                default:
                                        
                                       if(option[i][0]=='@' ) {
                                       	      if (option[i][1..sizeof(option[i])-1]!=mud_nname())
                                       	      {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])-1],
                                                        //me, opt_long);
                                                        me, replace_string(arg,option[i],""));
                                                write("网路讯息已送出，请稍候。\n");
                                                return 1;
                                              }
                                              else
                                              {
                                              	return main(this_player(),replace_string(arg,option[i],""),remote);
                                              	}
                                        }
                                        //先于该玩家所处的环境中找寻被查玩家。
                                        ob1 = present(option[i], environment(me));
                                        //如果没找到，则在所有玩家列表中找寻。
                                        if (!ob1) ob1 = find_player(option[i]);
                                        //如果还是没找到，则在所有生物列表中找寻。
                                        if (!ob1) ob1 = find_living(option[i]);
                                        if (!ob1)
                                        {
                                        	list = users();
                                         	for(j=0;j<sizeof(list);j++)
                                         	{
                                         	 if (list[j]->query("name") == option[i])
                                         	   {ob1 = list[j];break;}
                                         	}
                                        }
                                        if (!ob1) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-p] [<ID>]\n");
                                       // if ( objectp(this_player()) && userp(this_player())&& !wizardp(this_player()) && !this_player()->visible(ob1))
                                        if ( objectp(me) && userp(me) && !wizardp(me) && !me->visible(ob1))
                                        	return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-p] [<ID>]\n");
                                        /* 由于下面这行，使得当who + 巫师名时，无论该巫师隐身与否，玩家都能
                                           看见，加了上面这行便避免了这种情况的发生。Modified by Spacenet */
                                        me = ob1; opt_party = 1;
                        }
        }

        if( objectp(me) && userp(me) && opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 5 )
                        return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
                me->receive_damage("jing", 5);
        }
	//根据不同的参数设置表头。
        str = HIG "◎"+MUD_NAME+HIG "◎"+HIW+"    目前江湖中的 " NOR;
        if(opt_party)
                if(me->query("family/family_name"))
                        str += HIR+"("+me->query("family/family_name")+") "+NOR;
                else str += HIR + "(无门派) " + NOR;
        if ( opt_wiz )
                str += "神仙有：";
        else
                if ( opt_long ) str += "玩家有：";
                else str += "总人物有：";

        str += "\n";
        str +=
                HIC"≡"+HIY"───────────────────────────────────"HIC"≡\n"NOR;
        ob = filter_array( objects(), (: visiblep :) );
        if (opt_party) {
               //在数组ob中找寻符合party指定的同门玩家。	
               ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
                        }
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;   //ppl_cnt ?= party player count（同门玩家数）。
        
        //处理who -l的情况。
        if( opt_long )
        {
               //按照门派分类列出玩家。	
               for (fac_no=0; fac_no<fac_amt; fac_no++)
               {           	
                       i = sizeof(list);
                       while ( i-- )
                       {
                                if( interactive(list[i]) )
                                	ppl_cnt++;
                                //把同门的玩家列在一起。	
                                if( list[i]->query("family/family_name") == faction_name[fac_no])
                                        str = sprintf("%s%12s%s%s\n",
                                                str,
                                                RANK_D->query_rank(list[i]),
                                                //根据玩家当前状态（发呆，断线）分别加上不同标志。
                                                interactive(list[i])?(query_idle(list[i]) > 150? HIG "*" NOR:" "):HIR "#" NOR,
                                                list[i]->short(1));
			}
                }
                //处理无门派玩家。
                i = sizeof(list);
                while ( i-- )
                {
                        if( interactive(list[i]) )
                        ppl_cnt++;
                        if(!list[i]->query("family") )
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                }
        } else  if( opt_wiz )  //处理who -w的情况。
                {
                        i = sizeof(list);
                        while( i-- )
                        {
                                if (interactive(list[i]))
                                ppl_cnt++;
                                if (!wizardp(list[i]) ) continue;
                                if (list[i]->query("no_look_wiz")) continue;
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                        }
        } else  if( opt_exp )  //处理who -e的情况。
                {
                	      list = sort_array(list,(: $1->query("combat_exp") - $2->query("combat_exp") :));
                        i = sizeof(list);
                        while( i-- )
                        {
                            //    if (interactive(list[i]))
                            //    ppl_cnt++;
                                if (wizardp(list[i]) && !list[i]->query("no_look_wiz")) continue;
                                str = sprintf("%s%12s%s%s\n",
                                        str,
                                        RANK_D->query_rank(list[i]),
                                        interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
                                        list[i]->short(1));
                        }
                } else  //处理其他情况。
                {
                i = sizeof(list);
                while ( i-- )
                        {
                        if( interactive(list[i]) && wizardp(list[i]) && !list[i]->query("no_look_wiz") )
                                        name = sprintf( "%s"HIM"%-10s(%-11s"HIY"│",
                                                        " ",
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else if( interactive(list[i]) && query_idle(list[i]) > 150)
                                        name = sprintf( "%s%-10s(%-11s"HIY"│",
                                                        HIG"*"HIW,
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else if(list[i]->query_temp("netdead"))
                                        name = sprintf( "%s%-10s(%-11s"HIY"│",
                                                        HIR"#"HIW,
                                                        list[i]->name(1),
                                                        capitalize(list[i]->query("id"))+")");
                        else
                                        name = sprintf( HIW"%s%-10s(%-11s"HIY"│",
                                                        " ",
                                                       list[i]->name(1),
                                                       capitalize(list[i]->query("id"))+")");
                                        str = sprintf("%s%25s%s", str, name,
                                                ppl_cnt%3==2?"\n":"");
//                                        if (interactive(list[i]))
                                                ppl_cnt++;
                }
                if ( ppl_cnt%3 ) str += "\n";
        }

        str += HIC"≡"+HIY"───────────────────────────────────"HIC"≡\n"NOR;
        str = sprintf("%s共有 %s 位使用者连线中，系统负担：%s\n "HIG"*"NOR" 表示发呆中，"HIR"#"NOR" 表示断线中。", str, CHINESE_D->chinese_number(sizeof(list)),
                query_load_average());

        if( remote ) return str+"\n";
//      write(str + "\n");
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
}

int visiblep( object ob )
{
	if ( userp(ob) && environment(ob) ) {
    if( !objectp(this_player()) || !userp(this_player())) 
    {
      	if (!wizardp(ob)) return 1;
      	else if (!ob->query("env/invisibility")) return 1;
      	else return 0;
    }
		if(  wizardp(this_player()) ) return 1;
		if( !wizardp(this_player()) && this_player()->visible(ob) ) return 1;
	}
	return 0;
}
int help()
{
//write(@HELP
write("
指令格式 : who [-h] [-l] [-w] [-p] [<ID>]

    这个指令可以列出所有在线上的玩家及其等级。

-h 列出帮助屏幕。
-l 选项列出较长的讯息。
-p 只列出同门的玩家。
-w 只列出线上所有的巫师。
<ID> 列出<ID>代表玩家所属门派的玩家。

    who @mudname 则显示其他联网泥巴里的玩家。

"HIG"*"NOR" 表示"HIG"发呆"NOR"中，"HIR"#"NOR" 表示"HIR"断线"NOR"中。

相关指令： finger
"
    );
    return 1;
}



