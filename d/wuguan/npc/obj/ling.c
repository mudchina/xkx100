// d/wuguan/obj/ling.c 基本的忠诚

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("推荐令", ({"tuijian ling", "ling"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是从陈有德那里得到推荐令。有了它，你可以和武馆内的本门弟子\n"+
		"一起探讨(tantao)武功了。\n");
		set("unit", "块");
		set("no_get",1);
		set("no_get_from",1);
		set("no_put",1);
		set("no_give",1);
	}
}
init()
{
	add_action("do_tantao","tantao");
}
int do_tantao(string arg)
{
 	object me=this_player();
	object env=environment(me);
	object ob;
	string type,with;
  string my_fam = me->query("family/family_name");
	if (strsrch(file_name(env),"d/wuguan/") < 0)
		return notify_fail("出了武馆，谁还认识你的推荐令？\n");
	if (!arg ||sscanf(arg,"%s with %s",type,with)!=2)
		return notify_fail("格式：tantao <技能> with <某人>\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("等你忙完了再来吧。\n");
	if (type!="force" && type!="dodge" && type!="parry")
		return notify_fail("你只能和别人讨论基本内功、基本轻功和基本招架的内容。\n");
	if( !objectp(ob = present(with, environment(me))))
		return notify_fail("你想和谁一起讨论？\n");
	if (!me->query("family"))
	 return notify_fail("你还是先加入一个门派再和别人讨论问题吧。\n");
	 if (me->query("jing")<20)
	 return notify_fail("你现在太累了，休息一下再来吧。\n");
 	if ((me->query("potential") - me->query("learned_points"))< 2)
		return notify_fail("你的潜能不够和人家一起讨论问题了。\n");
	if((my_fam=="逍遥派" && ob->query("id")=="xiaoyao dizi")
	||(my_fam=="明教" && ob->query("id")=="mingjiao bangzhong")
	||(my_fam=="桃花岛" && ob->query("id")=="taohuadao dizi")
	||(my_fam=="少林派" && ob->query("id")=="xiao heshang")
	||(my_fam=="神龙教" && ob->query("id")=="shenlong dizi")
	||(my_fam=="云龙门" && ob->query("id")=="tiandihui bangzhong")
	||(my_fam=="泰山派" && ob->query("id")=="taishan dizi")
	||(my_fam=="凌霄城" && ob->query("id")=="lingxiao dizi")
	||(my_fam=="姑苏慕容" && ob->query("id")=="murong dizi")
	||(my_fam=="星宿派" && ob->query("id")=="xingxiu dizi")
	||(my_fam=="古墓派" && ob->query("id")=="gumu dizi")
	||(my_fam=="铁掌帮" && ob->query("id")=="tiezhang dizi")
	||(my_fam=="峨嵋派" && ob->query("id")=="xiao shitai")
	||(my_fam=="全真教" && ob->query("id")=="daotong")
	||(my_fam=="五毒教" && ob->query("id")=="wudu dizi")
	||(my_fam=="恒山派" && ob->query("id")=="hengshan nvni")
	||(my_fam=="衡山派" && ob->query("id")=="hengshan dizi")
	||(my_fam=="青城派" && ob->query("id")=="qingcheng dizi")
	||(my_fam=="红花会" && ob->query("id")=="honghuahui bangzhong")
	||(my_fam=="雪山寺" && ob->query("id")=="xueshan dizi")
	||(my_fam=="白驼山派" && ob->query("id")=="baituo dizi")
	||(my_fam=="黑木崖" && ob->query("id")=="riyuejiao dizi")
	||(my_fam=="昆仑派" && ob->query("id")=="kunlun dizi")
	||(my_fam=="南少林派" && ob->query("id")=="nanshaolin dizi")
	||(my_fam=="华山派" && ob->query("id")=="huashan dizi")
	||(my_fam=="嵩山派" && ob->query("id")=="songshan dizi")
	||(my_fam=="武当派" && ob->query("id")=="daotong")
	||(my_fam=="大理段家" && ob->query("id")=="tianlongsi dizi")
	|| (my_fam=="丐帮" && ob->query("id")=="xiao jiaohua"))
		{
		if (me->query("teachwg/"+type)>=100)
		return notify_fail("这样武功你已经问得差不多了，换个话题吧。\n");
		else if(me->query_skill(type,1) < me->query("teachwg/"+type) )
			return notify_fail("这样武功你自己没学到多少啊，怎么和别人一起讨论。\n");
		else 
			{
				tell_object(me,"你开始和"+ob->query("name")+"一起讨论关于"+to_chinese(type)+"的问题。\n");
				if (random(5)<2)
					tell_object(me,"你和"+ob->query("name")+"讨论了一会儿,谁也没明白谁的意思。\n");
				else
					{
					tell_object(me,"你和"+ob->query("name")+"讨论了一会儿，对"+to_chinese(type)+"的理解更深了一些。\n");
					me->add("family/fealty",3);
					write(HIW"你对自己以后在"+me->query("family/family_name")+"的发展前景更有信心了。\n"NOR);
					me->add("teachwg/"+type,1);
					me->add("learned_points",2);
					me->improve_skill(type, 2*me->query("teachwg/"+type));
			    }
			}
				me->add("jing",-(10+random(5)));
				return 1;
			}
			else
	 			return notify_fail("看起来"+ob->query("name")+"没有和你一起讨论问题的意思。\n");	
}