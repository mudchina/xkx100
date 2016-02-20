// bug.c
inherit F_CLEAN_UP;
 
#include <ansi.h>
 

 
int main(object me, string arg)
{
        object ob;

        string sp, add;
        int bug, bugp , flag;

        seteuid(getuid(me));

        if (! arg || !wizardp(me))
                ob = me;
        else
        if (wizardp(me) )
        {
                // 添加 bug 点数
                if (sscanf(arg, "%s %d", arg, bug) == 2)
                {
                        if (bug == 0)
 	                        return notify_fail("你到底是想添加还是"
                                                   "减少？\n");
                        if (! objectp(ob = find_player(arg)))
                                ob = LOGIN_D->find_body(arg);
                        if (! objectp(ob))
                        {
                            ob = new(USER_OB);
                            seteuid(arg);
                            export_uid(ob);
                            flag = 1;
                            if (!ob->restore())
                            {
                            	destruct(ob);
                            	return notify_fail("没有这个玩家。\n");
                            }
                        }
                        ob->add("bug", bug);
                        ob->add("bug_count",bug);
                        ob->save();
                        sp = sprintf("用户 " WHT "%s" NOR " 的报告点数"
                                     "增加了 " WHT "%d" NOR " 点，现为"
                                     WHT " %d " NOR "点。\n", arg, bug,
                                     ob->query("bug", 1));

                        if (bug > 0)
                        tell_object(ob, HIG + me->name() + "增加了你的 " +
                                        bug + " 点报告点数。\n" NOR);
                        else 
                        tell_object(ob, HIG + me->name() + "减少了你的 " +
                                        -bug + " 点报告点数。\n" NOR);
                        

                        log_file("static/bug", sprintf("[%s] wizard %s a"
                                 "dd   %d bug point to user %s.\n",
                                 ctime(time()), getuid(me), bug, getuid(ob)));

                        //UPDATE_D->global_destruct_player(ob);

                        tell_object(me, sp);
                        if (flag == 1) destruct(ob);
                        return 1;
                }
                
                ob = present(arg, environment(me));
                if (! ob || ! ob->is_character()) ob = find_player(arg);
                if (! ob || ! ob->is_character()) ob = LOGIN_D->find_body(arg);
                if (! objectp(ob))
                {
                   ob = new(USER_OB);
                   seteuid(arg);
                   export_uid(ob);
                   flag = 1;
                   if (!ob->restore())
                   {
                    	destruct(ob);
                     	return notify_fail("没有这个玩家。\n");
                    }
                 }
                if (base_name(ob)!=USER_OB)
                {
                	if (flag == 1) destruct(ob);
                    return notify_fail("只有玩家才具有此参数。\n");
                }
                        
        }
 
        bug = ob->query("bug", 1);

        if (! bug)
                sp = ((ob == me ? "你" : ob->name()) + "在" +
                         MUD_NAME + NOR "中尚无报告过任何错误。\n");
        else
                sp = ((ob == me ? "你" : ob->name()) + "在" +
                         MUD_NAME + NOR "中的错误报告积累点数为"
                         HIC + bug +"/"+ob->query("bug_count")+ NOR "点。\n");

        tell_object(me, sp);
        if (flag == 1) destruct(ob);
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式： bugs
           bugs       <对象名称>               (巫师专用)
           bugs       [<对象名称> <点数>]      (巫师专用)

这个指令可以显示你在游戏中的错误报告积累点数。玩家可通过
此点数获得一些奖励。如果有巫师在线，可直接在公众频道汇报
错误，这时巫师可视 BUG大小给玩家增加报告点数。如游戏中无
巫师在线，请用正式ID留言到巫师会客室或BUG留言室，我们会
在第一时间内修复 BUG及给此ID增加报告点数。（注意，只有汇
报 BUG的ID才能获得点数。如果一个 BUG被数个玩家同时发现，
报告点数将加到最先汇报此 BUG的ID上。）

巫师可以使用添加或者减少玩家的报告点数。

细小错误：1点           (含错别字、语句不通、帮助遗漏等)
一般错误：3点           (不会影响到游戏正常进行的错误)
严重错误：5点           (视情况而论、包含某些系统错误)
练功错误：10至1000点    (有益于自身修炼及获得利益的错误)

HELP);
        return 1;
}

