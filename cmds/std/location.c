// location.c
inherit F_CLEAN_UP;

#include <ansi.h>



string *place_desc = ({
	"扬州城的武庙",
	"扬州城的富春茶社",
	"扬州城的武道场",
	"扬州城的飞雪堂",
	"扬州城的武馆大厅",
	"扬州城的秦淮客寓",
	"北京城的客店",
	"成都城的锦城驿",
	"苏州城的客店",
	"杭州城的天外天",
	"福州城的榕城驿",
	"兰州城的顺风客栈",
	"泉州城的鸿福楼",
	"大理城的客店",
	"长安城的云来客栈",
	"江陵城的晴川客栈",
	"襄阳城的襄阳客栈",
	"无锡城的客店",
	"岳阳城的牡丹楼",
	"扬州的十里长街",
	"杭州的青石大道",
	"杭州的苏堤",
	"少林寺的松树林",
	"武当山的林间小径",
	"峨嵋山的九十九道拐",
	"昆仑山的昆仑山路",
	"华北的大驿道",
	"大理的官道"
});
int main(object me, string arg)
{
	object ob, where,tbg;
	mapping fam,fam2;
	int sp, dp, i, cost, count_lvl, bibo_lvl, placeno;
	string *dir, *place;

	seteuid(getuid());

	if( (!(fam = me->query("family")) || fam["family_name"] != "桃花岛") )
		return notify_fail("只有桃花岛入门弟子才能推算别人的所在！\n");
	if (me->is_busy())
		return notify_fail("你上一个动作还没有完成！\n");
	if( !present("tie bagua", me))
		return notify_fail("没有铁八卦，恐怕没法推算别人的所在！\n");

	tbg= present("tie bagua", me);
	if(tbg->query("ownmake")==1)
//	fam2 = me->query("weapon");
//	if(fam2["id"] == "tie bagua")
		return notify_fail("恐怕这个铁八卦不行吧！\n");
	
	count_lvl = me->query_skill("count",1);
	bibo_lvl = me->query_skill("bibo-shengong",1);
	if( bibo_lvl < 30 && !wizardp(me))
		return notify_fail("你桃花岛武功尚未入门，无法做出推算！\n");
	if( count_lvl < 30 && !wizardp(me))
		return notify_fail("你的阴阳八卦尚未纯熟，无法推算别人的所在！\n");
	if ( !arg ) return notify_fail("你要推算谁的所在？\n");
	if ( present(arg, environment(me)) )
		return notify_fail("你要推算的人就在边上，你不是有毛病吧？\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要推算谁的所在？\n");
	if (wizardp(ob) && !wizardp(me))
		return notify_fail("你要推算谁的所在？\n");
	if ( ob == me )
		return notify_fail("你没这么笨吧，要别人告诉你自己在哪里？\n");
	cost = me->query("max_jing")/(1+me->query_skill("count",1)/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法去推算别人的所在。\n");

	message_vision( CYN"$N拿起一只铁八卦屏心凝气，拇指依次掐向铁八卦上子、丑、寅、卯、辰、巳、午、未、申、酉、戌、亥各个方位，细心推算起来……\n\n\n"NOR, me);
	message_vision("口中念念有词，忽然脸露微笑: 有了！\n\n",me);
	me->start_busy(3);

	sp = count_lvl*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;

	tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......\n"NOR);
	if ( random(sp) < random(dp)/2 )
		return notify_fail( "你又颓然坐下，摇了摇头，说道：不对的！\n");

	me->receive_damage("jing", cost );
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在哪里耶...\n");
	if (random(10) > 7)
	{
		printf("%s现在可能在%s。\n",
		(string)ob->name(), place_desc[random(sizeof(place_desc))]);
		return 1;
	}
	dir = get_dir("/d/");
	if ( random(sp) < random(dp) || count_lvl < 100)
	{
		for (i=0; i<sizeof(dir); i++)
			if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
				return notify_fail(ob->name()+ "现在可能在"+to_chinese(dir[i])+"的某个地方！\n");
		return notify_fail( ob->name()+"现在在哪里呢？不知道啊！\n");
	}
	if ( random(sp) < random(dp) || bibo_lvl < 100)
	{
		for (i=0; i<sizeof(dir); i++)
			if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
			{
				place = get_dir("/d/"+dir[i]+"/");
				placeno = random(sizeof(place));
				if(strsrch(place[placeno], ".c") >= 0)
				{
					if(!( where = find_object("/d/"+dir[i]+"/"+place[placeno])))
						where = load_object("/d/"+dir[i]+"/"+place[placeno]);
					return notify_fail(ob->name()+ "现在可能在"+to_chinese(dir[i])+"的"+where->query("short")+"！\n");
				}
				else return notify_fail(ob->name()+ "现在可能在"+to_chinese(dir[i])+"的某个地方！\n");
			}
		return notify_fail( ob->name()+"现在在哪里呢？不知道啊！\n");
	}
	for (i=0; i<sizeof(dir); i++)
		if (strsrch(file_name(where), "/"+dir[i]+"/") >= 0)
		{
			printf("%s现在可能在%s的%s。\n", ob->name(), to_chinese(dir[i]), where->query("short"));
			return 1;
		}
	return notify_fail("这个人不知道在哪里耶...\n");
}

int help(object me)
{
	write(@HELP
指令格式: location <玩家的 ID>

    这个指令是桃花岛弟子用来得知玩家目前所在的位置。

HELP
	);
	return 1;
}

