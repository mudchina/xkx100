// /cmds/usr/set.c

// Modified by Constant Jan 4 2001
inherit F_CLEAN_UP;
 
#define MAX_ENV_VARS	20
 


// 增加以下两个数组，用于判断环境变量设置的合法性。
// Added by Constant Jan 4 2001
string *player_settings = ({
	"brief",
	"brief1",
	"brief2",
	"combatd",
	"combatd2",
	"no_accept",
	"no_teach",
	"no_mail",
	"no_map",
	"no_tell",
	"prompt",
	"public",
	"verbose",
	"wimpy",
	"auto_regenerate",
	"halt_age",
	"no_fight",
	"can_tell",
	"auto_reply",
});

string *wizard_settings = ({
	"immortal",
	"invisibility",
	"msg_home",
	"msg_min",
	"msg_mout",
	"msg_clone",
	"msg_desg",
	"combat",
	"trace_error",
	"no_task_msg"
});
 

int help();
 
int main(object me, string arg)
{
	int i;
	string term, *terms;
	mixed data;
	mapping env;
 
	if ( me != this_player(1) ) 
		return 0;
 
	env = me->query("env");
 
	if ( !arg || arg=="" ) {
		write("你目前设定的环境变数有：\n");
		if ( !mapp(env) || !sizeof(env) )
			write("\t没有设定任何环境变数。\n");
		else {
			terms = keys(env);
			for (i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	if ( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}
 
	if ( term && term!="" ) {
		if ( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("你设的环境变量太多了，请先用 unset 删掉几个吧。\n");

		if ( member_array(term, player_settings) == -1 ) {
			if (!wizardp(me))
				return notify_fail("没有这种环境变量，请参照帮助。\n");
			else if ( member_array(term, wizard_settings) == -1)
				return notify_fail("没有这种环境变量，请参照帮助。\n");
		}
		if ((wiz_level(me) == 0) &&
			(member_array(term, wizard_settings) != -1))
			return notify_fail("只有巫师能用这个设定。\n");

		sscanf(data, "%d", data);
		me->set("env/" + term, data);
		printf("设定环境变数：%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
指令格式：set <变量名> [<变量值>]
 
    这个指令让你设定一些环境变量，不加参数时会显示你目前设定
的环境变量，不指定变量值，则默认值为 "YES"。这些变量会随着你
的人物被储存下来。
 
    取消变量设定请用 unset 指令。
 
    至于有哪些环境变量可以设定，请见 help setup。
TEXT
	);
	return 1;
}

