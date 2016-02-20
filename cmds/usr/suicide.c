// suicide.c
inherit F_CLEAN_UP;

#include <ansi.h>



private int halt_suicide(object me);
private int slow_suicide(object me);
int sure1(string arg,object me,string skill,string pfm);
int sure2(string arg,object me,string skill,string lskill);
int scborn(object me,string arg);
varargs private void check_scborn(string passwd, object me, string skill,string etc1,string etc2);

int main(object me, string arg)
{
	object *inv;
	string *args;
	int i;
	
	seteuid(getuid());
	if( me->is_busy() )
		return notify_fail("你上一个动作还没完成。\n");
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if( userp(inv[i]))
		return notify_fail("你身上还有个大活人呢，想不开也别急呀？\n");
	}
	if( !arg )
		return notify_fail("自杀有两种，您是要永远死掉(-f)还是重新投胎(-r)？\n");
	args = explode(arg," ");
	if (args[0]!="-f" && args[0]!="-r")
		return notify_fail("自杀有两种，您是要永远死掉(-f)还是重新投胎(-r)？\n");
	if (args[0]=="-f")
	{
		write("如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n考虑清楚，确定的话请输入您的密码：");
		input_to("check_password", 1, me, 1);
		return 1;
	}
	return scborn(me,implode(args[1..sizeof(args)-1]," "));
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n你决定要自杀了，如果二十秒内不后悔，就真的永别了。\n\n\n" NOR);
		me->set_temp("suicide_countdown", 8);
		me->start_busy( (: slow_suicide,me :),(: halt_suicide,me :));
	}
}
private int halt_suicide(object me)
{
	tell_object(me,"你想起了泥潭里的谈笑风生，还是打消了寻死的念头。\n");
	me->delete_temp("suicide_countdown");
	return 1;
}
private int slow_suicide(object me)
{
	object link_ob;
	int stage;
	string id;

	stage = me->query_temp("suicide_countdown");
	link_ob = me->query_temp("link_ob");
	if( !link_ob || !stage ) return 0;
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( (stage-1)%5 == 0 || stage < 6)
			tell_object(me, HIR "你还有 " + (stage-1)*2 + " 秒的时间可以后悔(halt)。\n" NOR);
		return 1;
	}


	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	id=geteuid(me);
	if (!id) id=getuid(me);
	link_ob->save();
	me->save();
	cp( link_ob->query_save_file() + __SAVE_EXTENSION__,sprintf(DATA_DIR "suicide/login/%c/%s"+ __SAVE_EXTENSION__, id[0], id));
	cp(      me->query_save_file() + __SAVE_EXTENSION__,sprintf(DATA_DIR "suicide/user/%c/%s" + __SAVE_EXTENSION__, id[0], id));
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm(      me->query_save_file() + __SAVE_EXTENSION__ );
		write("好吧，永别了:)。\n");
	tell_room(environment(me), me->name() +
		"自杀了，以后你再也看不到这个人了。\n", ({me}));
  message("channel:sys",HIR"【系统】频道精灵："+me->name()+"("+id+")自杀了。\n"NOR,users());
	destruct(link_ob);
	destruct(me);
	return 0;
}
int scborn(object me,string arg)
{
	int times;
	string skill,lskill,fskill,skill2,skill3;
	string pfm;
	int i;
	string *cant;
	mixed dir;
	string str;
	string temp;
	
	notify_fail("你没法转生。\n");
	if (!SCBORN_D->valid_scborn(me) && me->query("id")!="trya")
		return 0;
	times = SCBORN_D->query_scborn_times(me);
// 一转 应该是 reborn(user,"taiji-quan","zhen"); 保存taiji-quan和pfm zhen
// 二转 应该是 reborn(user,"taiji-quan","literate"); 保存 两个技能
// 三转 应该是 reborn(user,"taiji-quan","taiji-shengong"); 保存
// 四转 应该是 reborn(user,"taiji-quan","taiji-jian");
// 五转 应该是 reborn(user,"taiji-quan","taiji-jian","huifeng-jian");
// 六转 应该是 reborn(user);
	switch(times)
	{
		case 0:
			if (!arg) 
				return notify_fail("第一次转生格式为：suicide -r 武功 绝招\n");
			if (sscanf(arg,"%s %s",skill,pfm)!=2)
				return notify_fail("第一次转生格式为：suicide -r 武功 绝招\n");
			//检查武功
			if (!me->query_skill(skill))
				return notify_fail("你并不会这个武功。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("你还不能保留知识技能。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("你还不能保留内功。\n");
      //检查pfm
			if (file_size(SKILL_D(skill+"/"+pfm+".c"))<0)
			{
				write(to_chinese(skill)+"并没有"+pfm+"这个特殊用法\n");
				write("不保留武功的特殊使用吗？(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
			}
			if ( !me->query("perform/"+pfm) && !SCBORN_D->valid_perform(me,skill,pfm))
			{
				write("你还无法保留"+to_chinese(skill)+"的"+SKILL_D(skill+"/"+pfm)->name()+"这个特殊用法，可能是你没学会或者这个武功不需要从掌门处学到。\n");
				write("不保留武功的特殊使用吗？(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;				
			}
			write("您选择了转生时保留武功："+to_chinese(skill)+"，以及相应的绝招："+SKILL_D(skill+"/"+pfm)->name()+"。\n");
			write("请输入您的密码以确认：");
			input_to("check_scborn",me,skill,pfm);
			break;
		case 1:
			if (!arg)
				return notify_fail("转生格式为：suicide -r 武功 知识技能\n");
			if (sscanf(arg,"%s %s",skill,lskill)!=2)
				return notify_fail("转生格式为：suicide -r 武功 知识技能\n");
			//检查武功
			if (!me->query_skill(skill))
				return notify_fail("你并不会这个"+skill+"武功。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("选择的武功不能是知识技能。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("你不能不能保留内功。\n");
			//检查知识技能
			if (!me->query_skill(lskill))
				return notify_fail("你并不会"+lskill+"这项技能。\n");
			if ((SKILL_D(lskill)->type())!="knowledge")
				return notify_fail(lskill+"并不是一种知识技能。\n");
			dir = get_dir("kungfu/skill/"+skill+"/");
			cant = ({});
			for (i=0;i<sizeof(dir);i++)
			{
				pfm = dir[i];
				if (dir[i][<2..<1]==".c") 
					pfm = dir[i][0..<3];
				if ( !me->query("perform/"+pfm)
				&& !SCBORN_D->valid_perform(me,skill,pfm) )
					cant += ({ ("kungfu/skill/"+skill+"/"+pfm)->name() });
			}
			if (arrayp(cant))
			{
				str = "你无法保留"+to_chinese(skill)+"的"+implode(cant,"、")+"特殊用法。\n";
				str += "你不会使用这些技能，或者没有从掌门处学得。\n";
				write(str+"不保留这部分的特殊使用吗？(y/n)");
				input_to("sure2",me,skill,lskill);
				return 1;								
			}
			write("您选择了二次转生时保留武功："+to_chinese(skill)+"，以及知识技能："+to_chinese(lskill)+"。\n");
			write("请输入您的密码以确认：");
			input_to("check_scborn",me,skill,lskill);
			break;
		case 2:
			if (!arg)
				return notify_fail("转生格式为：suicide -r 武功 内功\n");
			if (sscanf(arg,"%s %s",skill,fskill)!=2)
				return notify_fail("转生格式为：suicide -r 武功 内功\n");
			//检查武功
			if (!me->query_skill(skill))
				return notify_fail("你并不会"+skill+"这个武功。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("知识技能会全部保存，不需要特别指出。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("你只能保存一种内功。\n");
			//检查内功
			if (!me->query_skill(fskill))
				return notify_fail("你并不会"+fskill+"这项技能。\n");
			if (!(SKILL_D(fskill)->valid_enable("force")))
				return notify_fail(fskill+"并不是一种特殊内功。\n");
			write("您选择了三次转生时保留武功："+to_chinese(skill)+"，以及内功技能："+to_chinese(fskill)+"。\n");
			write("请输入您的密码以确认：");
			input_to("check_scborn",me,skill,fskill);
			break;
		case 3:
			if (!arg)
				return notify_fail("转生格式为：suicide -r 武功 武功\n");
			if (sscanf(arg,"%s %s",skill,skill2)!=2)
				return notify_fail("转生格式为：suicide -r 武功 武功\n");
			//检查武功1
			if (!me->query_skill(skill))
				return notify_fail("你并不会"+skill+"这项技能。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("四转会保存知识技能，不需要特别指出。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("四转会保存所有内功，不需要特别指出。\n");
			//检查武功2
			if (!me->query_skill(skill2))
				return notify_fail("你并不会"+skill2+"这项技能。\n");
			if ((SKILL_D(skill2)->type())=="knowledge")
				return notify_fail("四转会保存知识技能，不需要特别指出。\n");
			if (SKILL_D(skill2)->valid_enable("force"))
				return notify_fail("四转会保存所有内功，不需要特别指出。\n");
			write("您选择了四次转生时保留武功："+to_chinese(skill)+"，以及武功："+to_chinese(skill2)+"。\n");
			write("请输入您的密码以确认：");
			input_to("check_scborn",me,skill,skill2);
			break;
		case 4:
			if (!arg)
				return notify_fail("转生格式为：suicide -r 武功 武功\n");
			if (sscanf(arg,"%s.%s %s",skill,skill2,skill3)!=3)
				return notify_fail("转生格式为：suicide -r 武功 武功\n");
			//检查武功1
			if (!me->query_skill(skill))
				return notify_fail("你并不会"+skill+"这项技能。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("五转会保存知识技能，不需要特别指出。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("五转会保存所有内功，不需要特别指出。\n");
			//检查武功2
			if (!me->query_skill(skill2))
				return notify_fail("你并不会"+skill2+"这项技能。\n");
			if ((SKILL_D(skill2)->type())=="knowledge")
				return notify_fail("五转会保存知识技能，不需要特别指出。\n");
			if (SKILL_D(skill2)->valid_enable("force"))
				return notify_fail("五转会保存所有内功，不需要特别指出。\n");
			//检查武功3
			if (!me->query_skill(skill3))
				return notify_fail("你并不会"+skill3+"这项技能。\n");
			if ((SKILL_D(skill3)->type())=="knowledge")
				return notify_fail("五转会保存知识技能，不需要特别指出。\n");
			if (SKILL_D(skill3)->valid_enable("force"))
				return notify_fail("五转会保存所有内功，不需要特别指出。\n");
			write("您选择了五次转生时保留武功："+to_chinese(skill)+"、武功："+to_chinese(skill2)+" 以及武功："+to_chinese(skill3)+" 。\n");
			write("请输入您的密码以确认：");
			input_to("check_scborn",me,skill,skill2,skill3);
			break;
		case 5:
			write("您决定了第六次转生。\n");
			write("请输入您的密码以确认：");
			input_to("check_scborn",me);
			break;
		default:
			return notify_fail("并没有提供六转以上转生。\n");
	}
	return 1;
}

int sure1(string arg,object me,string skill,string pfm)
{
	if (!arg)
	{
				write("不保留武功的特殊使用吗？(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
	}
	if (arg[0]=='y' || arg[0]=='Y')
	{
			write("您选择了转生时保留武功："+to_chinese(skill)+"且不保留任何绝招。\n");
			write("请输入您的密码以确认：");
		input_to("check_scborn",me,skill,0);
	}
	return 1;
}
int sure2(string arg,object me,string skill,string lskill)
{
	if (!arg)
	{
				write("不保留部分特殊使用吗？(y/n)");
				input_to("sure2",me,skill,lskill);
				return 1;
	}
	if (arg[0]=='y' || arg[0]=='Y')
	{
			write("您选择了转生时保留武功："+to_chinese(skill)+"且不保留部分绝招。\n");
			write("请输入您的密码以确认：");
		input_to("check_scborn",me,skill,lskill);
	}
	return 1;
}
varargs private void check_scborn(string passwd, object me, string skill,string etc1,string etc2)
{
	object link_ob;
	string old_pass;
	string id;
	string file;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	id = getuid(me);
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}
	SCBORN_D->reborn(me,skill,etc1,etc2);
//	write("你可以quit了。\n");
	me->move(VOID_OB,1);
	me->save();
	seteuid(getuid());
	file = sprintf(DATA_DIR "suicide/scborn/%s"+ __SAVE_EXTENSION__,  id);
	assure_file(file);
	cp(me->query_save_file() + __SAVE_EXTENSION__ ,file);
	"/cmds/usr/exit"->savequit(me);
}
int help (object me)
{
	write(@HELP
指令格式: suicide [-f|-r]
 
    如果因为某种原因你不想活了，你可以选择自杀来永远除去资料。系统会
要求你输入密码以确认身份。

suicide -r : 重新投胎
suicide -f : 永远的除去玩家资料，系统会要求你输入密码以确认身份。
 
请慎重选择 :)
 
HELP);
	return 1;
}
