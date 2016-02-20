// study.c
// 本命令没有考虑learn_bonus和practice_bonus。待考虑。
inherit F_CLEAN_UP;

#include <skill.h>


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name, book_name;
	string *args;
	mapping skill;
	int my_skill, cost, times, i, success=0;
	int j;

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (where->is_chat_room())
    return notify_fail("这里禁止练功。\n");
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");
//	if(sscanf(arg, "%s %d", book_name, times)!=2 )
//		return notify_fail("指令格式：study|du <书名> <次数>\n");
//取书名
	if (! arg || (i = sizeof(args = explode(arg, " "))) < 1)
         return notify_fail("指令格式：study|du <书名> <次数>\n");
        i--;
        if (i >= 1 && sscanf(args[i], "%d", times) && times)
                i--;
        else
                times = 1;
        if (args[i] == "with" && i >= 1)
                i--;
        book_name = implode(args[0..i], " ");


	if (times < 1 || times > 100)
		return notify_fail("读书次数最少一次，最多不能超过一百次。\n");
	if(!objectp(ob = present(book_name, me)) )
		return notify_fail("没这本书可读啊？\n");
	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西学到任何东西。\n");
	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	message("vision", me->name() + "正专心地研读" + ob->name() + "。\n", environment(me), me);
	if( (int)me->query("combat_exp") < skill["exp_required"] )
	{
		write("你的实战经验不足，再怎么读也没用。\n");
		return 1;
	}
	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(me) ) 
	return 0;
	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)me->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost
	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
	}
	if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太深奥了，毫无收获。\n");
	}
	if( !me->query_skill(skill["name"], 1)) me->set_skill(skill["name"], 0);
	my_skill = me->query_skill(skill["name"], 1);
	if( (string)SKILL_D(skill["name"])->type()=="martial" &&
			my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		{
			return notify_fail("也许是缺乏实战经验，你对"+ob->name()+"上面所说的东西总是无法领会。\n");
		}
		if (!me->query("env/auto_regenerate") && 
        				me->query("jing")< cost * times)
							return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");
	for (i = 0; i < times; i++)
			{        	

			if ((int)me->query("jing") > cost)
            me->receive_damage("jing", cost );
      else if (me->query("env/auto_regenerate") &&
                SKILL_D("force/regenerate")->exert(me, me))
              {
                        // try to regenerate & learn again
                        write("你觉得精神好了一些，继续读书。\n");
                        i--;
                        continue;
              } else
              {
                        me->set("jing", 0);
                        break;
              }
			}
	if (!i) 
		return notify_fail("你现在太累了，结果一行也没有看下去。\n");
	if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
				printf("你研读了"+chinese_number(i)+"行有关%s的技巧，对「%s」这一招似乎有些心得。\n", to_chinese(skill["name"]), zhao_name);
			else
				printf("你研读了"+chinese_number(i)+"行有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"]));

	for (j=0;j<i;j++)
	{
//原来的速度			me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+1);   
     me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/3+1);
	}
//	if (i < times)
//	return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");
	return 1;
}

int help(object me)
{
	write( @HELP
指令格式: study | du <物品名称> <次数>

    这个指令使你可以通过阅读秘笈或其他物品自学某些技巧，但前
提是: 你不能是个『文盲』。怎样脱盲？去学文化啦！

see also : learn
HELP
	);
	return 1;
}
