// /cmds/usr/unset.c

// Modified by Constant Jan 4 2001

inherit F_CLEAN_UP;

// 增加以下两个数组，用于检查环境变量设置的合法性。
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
	"trace_error"
	"no_task_msg"
});

int help();

int main(object me, string arg)
{
	if (!arg || arg=="") 
		return help();

	if (arg == "all") { 
		me->delete("env");
		write("你的环境变量已被清空。\n");
		return 1;
	}

	if (!me->query("env/" + arg))
		return notify_fail("你并没有设过这个环境变量。\n");

	if (member_array(arg, player_settings) == -1) {
		if (!wizardp(me))
			return notify_fail("没有这种环境变量，请参照帮助。\n");
		else if (member_array(arg, wizard_settings) == -1)
			return notify_fail("没有这种环境变量，请参照帮助。\n");
	}

	me->delete("env/" + arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：unset <变量名> | all

    这个指令让你删除环境变量的设定，若所带参数为all， 则删
除所有环境变量。

See also：set
TEXT
	);
	return 1;
}

