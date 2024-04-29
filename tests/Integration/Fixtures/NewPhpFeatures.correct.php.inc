<?php declare(strict_types=1);

namespace Lmc\CodingStandard\Integration\Fixtures;

class NewPhpFeatures
{
    public function __construct(private string $someString) // RequireConstructorPropertyPromotionSniff
    {
    }

    public function php80features(
        string|bool $foo, // UnionTypeHintFormatSniff
        int $bar, // RequireTrailingCommaInDeclarationSniff
    ): string|bool {
        $value = mt_rand(
            0,
            $bar, // RequireTrailingCommaInCallSniff
        );

        $dateOrNull = $this->mayReturnDateTimeOrNull();
        $timestamp = $dateOrNull?->getTimestamp(); // RequireNullSafeObjectOperatorSniff

        return $foo;
    }

    public function mayReturnDateTimeOrNull(): ?\DateTime
    {
        return null;
    }
}