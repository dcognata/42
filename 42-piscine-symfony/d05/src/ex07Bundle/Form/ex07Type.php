<?php

namespace ex07Bundle\Form;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;
use Symfony\Component\OptionsResolver\OptionsResolver;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\EmailType;
use Symfony\Component\Form\Extension\Core\Type\TextareaType;
use Symfony\Component\Form\Extension\Core\Type\DateTimeType;
use Symfony\Component\Form\Extension\Core\Type\CheckboxType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;

class ex07Type extends AbstractType
{
    /**
     * {@inheritdoc}
     */
    public function buildForm(FormBuilderInterface $builder, array $options)
    {
        $builder->add('username', TextType::class, array(
            'required' => false
        ))
        ->add('name', TextType::class, array(
            'required' => false
        ))
        ->add('email', EmailType::class, array(
            'required' => false
        ))
        ->add('enable', CheckboxType::class, array(
            'required' => false
        ))
        ->add('birthdate', DateTimeType::class, array(
            'required' => false
        ))
        ->add('address', TextareaType::class, array(
            'required' => false
        ))
        ->add('send', SubmitType::class);
    }

    /**
     * {@inheritdoc}
     */
    public function configureOptions(OptionsResolver $resolver)
    {
        $resolver->setDefaults(array(
            'data_class' => 'ex07Bundle\Entity\ex07'
        ));
    }

    /**
     * {@inheritdoc}
     */
    public function getBlockPrefix()
    {
        return 'ex07bundle_ex07';
    }


}
