// /d/obj/miling.c 密令

#include <ansi.h>
inherit ITEM;

string * help_str=({
"这封密令是要你去保护一位人质，将之送到安全的地点去。在途中，
不断会有各种杀手截杀人质，而人质本身是不堪一击的。途中会遇到
各种各样的状况，需要靠你自己的智慧去解决。\n",
"对人质而言：提供了如下命令以便保护者（你）使用：",
"baohu : 这条命令可以使人质处于“被保护”状态，而你将成为“保
        护者”，任何施加于人质的攻击都会自动地转施加在你身上
        （当然，需要你和人质在同一房间内）；",
"order ：这条命令可以“命令”人质做某件事；",
"	比如：order go east “命令”人质往东方走；",
"	具体可采用的命令可在实践中得到；\n",
"在护送过程中，当然你需要不断地用hp来查看人质的健康情况。一旦
人质到达目的地后，你将得到很高的奖励（具体奖励值视途中艰苦情
况而定）。",
});

string * search = get_dir("/d/");

int find_outdoor(string);

void init()
{
	add_action("do_read", "readling");
	add_action("do_help", "helpling");
	add_action("do_where", "whereis");
}

void create()
{
	set_name(HIY"密令"NOR, ({"mi ling", "ling", "ml"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是一张已经发黄的纸，上面歪歪曲曲地写着一些字，\n你可以用指令(readling)来读取，\n用指令(helpling)来看帮助，\n用指令(whereis)看地点说明。\n");
		set("value", 0);
		set("material","paper");
		set("unit", "纸");
		set("no_get", 1);
		set("no_drop", 1);
		set("describe","");
		set("src_add","");
		set("src_des","");
		set("dest_add","");
		set("dest_des","");
	}
}

int do_read()
{
	object me = this_player();

	tell_object(me,HIG"你这次的任务是："+query("describe")+"。\n"NOR);
	return 1;
}

int do_help()
{
	object me = this_player();
	int i;

	for (i=0;i<sizeof(help_str);i++)
		tell_object(me,HIY + help_str[i] +"\n"+NOR);
	return 1;
}

int do_where()
{
	object me = this_player();
	int i;
	string where;

	i = find_outdoor(query("src_des"));
	where = i < sizeof(search) ? to_chinese(search[i]) : "哪个地方的";
	tell_object(me,HIG"人质好象在"+where+"的"+query("src_add")+"\n"NOR);
	i = find_outdoor(query("dest_des"));
	where = i < sizeof(search) ? to_chinese(search[i]) : "哪个地方的";
	tell_object(me,HIG"要护送到好象在"+where+"的"+query("dest_add")+"\n"NOR);
	return 1;
}

int find_outdoor(string arg)
{
	int i = 0;

	while ( i < sizeof(search) ) {
		if (search[i] == arg)
			return i;
		i ++;
	}
	return i;
}

